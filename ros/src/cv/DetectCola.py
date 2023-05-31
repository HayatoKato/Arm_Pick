import cv2
import numpy as np

import torch
import torchvision

from torchvision.models.detection.faster_rcnn import FastRCNNPredictor

# カメラの登録
cap = cv2.VideoCapture(0)

# モデルロード
num_classes = 2
model = torchvision.models.detection.fasterrcnn_resnet50_fpn()
in_features = model.roi_heads.box_predictor.cls_score.in_features
model.roi_heads.box_predictor = FastRCNNPredictor(in_features, num_classes)
model.load_state_dict(torch.load(
    'pth_model/faster_rcnn.pth', map_location=torch.device('cuda')))
model = model.to("cuda")
model.eval()

while True:
    try:

        # 画像取得
        ret, frame = cap.read()  # 画像取得 [H, W, Ch]
        frame_width, frame_height = frame.shape[1], frame.shape[0]
        image = frame.copy()

        # モデル入力画像生成
        image_width, image_height = 480, 480
        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        image = cv2.resize(image, (image_width, image_height),
                           cv2.INTER_AREA).astype(np.float32)
        image = image.transpose(2, 0, 1)  # [H, W, Ch] → [Ch, H, W]
        image /= 255.0
        image = torch.from_numpy(image.astype(np.float32))
        image = image.to("cuda")

        # モデル推論
        prediction = model(image.unsqueeze(dim=0))
        box = prediction[0]["boxes"].cpu().detach().numpy()
        if len(box) != 0:
            box = box[0]
            xmin = int(box[0] / image_width * frame_width)
            ymin = int(box[1] / image_height * frame_height)
            xmax = int(box[2] / image_width * frame_width)
            ymax = int(box[3] / image_height * frame_height)
            cv2.rectangle(frame, (xmin, ymin), (xmax, ymax), (0, 255, 0))
        cv2.imshow("prediction", frame)
        cv2.waitKey(1)

    except KeyboardInterrupt:
        cap.release()
        cv2.destroyAllWindows()
        break
