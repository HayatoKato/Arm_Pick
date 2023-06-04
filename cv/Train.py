import os
import re
import cv2

import numpy as np
import matplotlib.pyplot as plt

from tqdm import tqdm


import torch
import torchvision
import albumentations as A

from albumentations.pytorch.transforms import ToTensorV2
from torchvision.models.detection.faster_rcnn import FastRCNNPredictor

import warnings
warnings.filterwarnings('ignore')


# デバイス選定
device = torch.device(
    'cuda') if torch.cuda.is_available() else torch.device('cpu')
print(f"used device = {device}")

# 画像ディレクトリ
imgs_dir = '../cola_img'


# データセットクラス
class ColaDetectionDataset(torch.utils.data.Dataset):

    def __init__(self, imgs_dir, width, height, transforms=None):
        self.transforms = transforms
        self.imgs_dir = imgs_dir
        self.height = height
        self.width = width

        # ファイル名
        self.img_files = [image for image in sorted(os.listdir(imgs_dir))
                          if image[-4:] == '.jpg']

        # class0 : 背景, class1 : mini Cola
        self.classes = ["", 'cola']

    def __getitem__(self, idx):

        img_name = self.img_files[idx]
        image_path = os.path.join(self.imgs_dir, img_name)

        # 画像読み込みと正規化
        img = cv2.imread(image_path)
        img_wt, img_ht = img.shape[1], img.shape[0]
        img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB).astype(np.float32)
        img_res = cv2.resize(
            img_rgb, (self.width, self.height), cv2.INTER_AREA)
        img_res /= 255.0

        # bounding box
        file_split = re.split("[/_.]", img_name)
        xmin = int(file_split[0].replace("lx", ""))
        ymin = int(file_split[1].replace("ly", ""))
        xmax = int(file_split[2].replace("rx", ""))
        ymax = int(file_split[3].replace("ry", ""))
        xmin_corr = (xmin/img_wt)*self.width
        xmax_corr = (xmax/img_wt)*self.width
        ymin_corr = (ymin/img_ht)*self.height
        ymax_corr = (ymax/img_ht)*self.height

        # アノテーション
        bbox = [[xmin_corr, ymin_corr, xmax_corr, ymax_corr]]  # bounding box
        bbox = torch.as_tensor(bbox, dtype=torch.float32)  # Tensor型変換
        area = (bbox[:, 3] - bbox[:, 1]) * (bbox[:, 2] - bbox[:, 0])  # 面積
        iscrowd = torch.zeros((bbox.shape[0],), dtype=torch.int64)
        label = torch.as_tensor([1], dtype=torch.int64)  # colaラベル
        image_id = torch.tensor([idx])

        target = {}
        target["boxes"] = bbox
        target["labels"] = label
        target["area"] = area
        target["iscrowd"] = iscrowd
        target["image_id"] = image_id

        # 画像の変換
        if self.transforms:
            sample = self.transforms(image=img_res, bboxes=bbox, labels=label)
            img_res = sample['image']
            target['boxes'] = torch.Tensor(sample['bboxes'])

        return img_res, target

    def __len__(self):
        return len(self.img_files)


# Transform指定関数
def get_transform(train=False):

    if train:
        return A.Compose([
            A.HorizontalFlip(p=0.5),
            A.RandomBrightnessContrast(p=0.9),
            A.ShiftScaleRotate(rotate_limit=20, p=0.9),
            ToTensorV2(p=1.0)
        ], bbox_params={'format': 'pascal_voc', 'label_fields': ['labels']})
    else:
        return A.Compose([
            ToTensorV2(p=1.0)
        ], bbox_params={'format': 'pascal_voc', 'label_fields': ['labels']})


# データセットインスタンス
dataset_train = ColaDetectionDataset(
    imgs_dir, 480, 480, transforms=get_transform(train=True))
dataset_test = ColaDetectionDataset(
    imgs_dir, 480, 480, transforms=get_transform(train=False))


# 画像とバウンディングボックスを描画
def plot_img_bbox(img, target):
    print(img.shape)

    box = target['boxes'][0]
    xmin, ymin, xmax, ymax = int(box[0]), int(box[1]), int(box[2]), int(box[3])

    cv_img = img.cpu().detach().clone().numpy()
    cv_img = cv_img.transpose(1, 2, 0)
    cv2.rectangle(cv_img, (xmin, ymin), (xmax, ymax), (0, 1, 0))
    plt.imshow(cv_img)
    plt.show()


# Augmentation確認
for image, targets in dataset_train:
    plot_img_bbox(image, targets)


# collate_fn関数
def collate_fn(batch):
    return tuple(zip(*batch))


# データローダー生成
dataloader_train = torch.utils.data.DataLoader(
    dataset_train, batch_size=8, shuffle=True, collate_fn=collate_fn)
dataloader_test = torch.utils.data.DataLoader(
    dataset_test, batch_size=1, shuffle=True, collate_fn=collate_fn)


# モデルロード
num_classes = 2  # クラス数
model = torchvision.models.detection.fasterrcnn_resnet50_fpn(pretrained=True)
in_features = model.roi_heads.box_predictor.cls_score.in_features
model.roi_heads.box_predictor = FastRCNNPredictor(in_features, num_classes)
model.to(device)

# 最適化関数
params = [p for p in model.parameters() if p.requires_grad]
optimizer = torch.optim.SGD(
    params, lr=0.005, momentum=0.9, weight_decay=0.0005)


# モデル学習
num_epochs = 10
for epoch in range(num_epochs):

    model.train()
    loss_accum = {"loss_rpn_box_reg": 0, "loss_classifier": 0,
                  "loss_box_reg": 0, "loss_objectness": 0}
    for n, (images, targets) in enumerate(tqdm(dataloader_train)):

        # 学習ステップ
        images = list(image.to(device) for image in images)
        targets = [{k: v.to(device) for k, v in t.items()} for t in targets]
        loss_dict = model(images, targets)
        losses = sum(loss for loss in loss_dict.values())

        # 学習更新
        optimizer.zero_grad()
        losses.backward()
        optimizer.step()

        # [ログ用]損失の蓄積
        for k, v in loss_dict.items():
            loss_accum[k] += v.cpu().detach().item()

    print_line = ""
    for k, v in loss_accum.items():
        print_line += f"{k} : {v:.4f}, "
    print(f"[epoch = {epoch+1}/{num_epochs}]")
    print(print_line)


# モデル保存
torch.save(model.cpu().state_dict(), './pth_model/faster_rcnn.pth')


# 学習済みモデル推論
model.eval()
with torch.no_grad():
    for n, (images, targets) in enumerate(dataloader_test):

        # 推論
        images = list(image.cpu() for image in images)
        prediction = model(images)
        box = prediction[0]["boxes"].cpu().detach().numpy()[0]
        xmin, ymin, xmax, ymax = int(box[0]), int(box[1]), int(box[2]), int(box[3])
        
        image = images[0].detach().numpy()
        image = image.transpose(1, 2, 0)
        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        
        cv2.rectangle(image, (xmin, ymin), (xmax, ymax), (0, 1, 0))
        cv2.imshow("prediction", image)

        # qを押すと止まる。
        if cv2.waitKey(100) & 0xFF == ord('q'):
            break