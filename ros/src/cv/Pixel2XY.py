import sys
import cv2
import numpy as np

import torch
import torchvision

from torchvision.models.detection.faster_rcnn import FastRCNNPredictor


# Cola情報
cola_radius = 2.5  # [cm]


# ArUco間距離情報
ar_width = 29.0  # [cm]
ar_height = 30.8  # [cm]
arm_ar0 = 16.5  # [cm]
arm_ar1 = 12.4  # [cm]


# ArUco検出用モデル
ar_pixels = dict.fromkeys(["0", "1", "2", "3"], 0)
dictionary = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
parameters = cv2.aruco.DetectorParameters()
detector = cv2.aruco.ArucoDetector(dictionary, parameters)


# モデルロード
num_classes = 2
model = torchvision.models.detection.fasterrcnn_resnet50_fpn()
in_features = model.roi_heads.box_predictor.cls_score.in_features
model.roi_heads.box_predictor = FastRCNNPredictor(in_features, num_classes)
model.load_state_dict(torch.load(
    'pth_model/faster_rcnn.pth', map_location=torch.device('cuda')))
model = model.to("cuda")
model.eval()


# カメラの登録
cap = cv2.VideoCapture(0)
img_height, img_width = 480, 640


# State1. ArUcoの認識
while True:
    try:

        # 画像取得
        ret, frame = cap.read()  # 画像取得[H, W, Ch]

        # ARマーカー認識
        corners, ids, _ = detector.detectMarkers(frame)

        # ARマーカー座標取得
        if ids is not None:
            for n, id in enumerate(ids):
                if (id[0] in [0, 1, 2, 3]):
                    ar_pixels[str(id[0])] = list(corners[n][0][0])

        # ARマーカー取得済み判定
        done = True
        for id, pixel in ar_pixels.items():
            if pixel == 0:
                done = False
                break

        # State1終了
        if done:
            break

    except KeyboardInterrupt:
        sys.exit()
        break

# ArUco検出時の画像ピクセル座標
src_topright = ar_pixels["0"]
src_topleft = ar_pixels["1"]
src_bottomleft = ar_pixels["2"]
src_bottomright = ar_pixels["3"]
source = np.array([src_topleft, src_topright, src_bottomright,
                  src_bottomleft], dtype=np.float32)

# 投影行列[GUI用]
offset = 10
gui_ratio_w = ar_width/ar_height
gui_ratio_h = ar_height/ar_width
gui_dst_topright = (int(480 * gui_ratio_w), 0)
gui_dst_topleft = (0, 0)
gui_dst_bottomleft = (0, int(480 * gui_ratio_h))
gui_dst_bottomright = (int(480 * gui_ratio_w), int(480 * gui_ratio_h))
gui_destination = np.array(
    [gui_dst_topleft, gui_dst_topright, gui_dst_bottomright, gui_dst_bottomleft], dtype=np.float32)
gui_homography_matrix = cv2.getPerspectiveTransform(source, gui_destination)

# 投影行列[座標算出用]
crd_dst_topright = (arm_ar0, 0)
crd_dst_topleft = (-arm_ar1, 0)
crd_dst_bottomleft = (-arm_ar1, ar_height)
crd_dst_bottomright = (arm_ar0, ar_height)
crd_destination = np.array([crd_dst_topleft, crd_dst_topright,
                           crd_dst_bottomright, crd_dst_bottomleft], dtype=np.float32)
crd_homography_matrix = cv2.getPerspectiveTransform(source, crd_destination)

# State2. 物体検出 + 座標算出
while True:
    try:

        # 画像取得
        ret, frame = cap.read()  # 画像取得 [H, W, Ch]
        frame_width, frame_height = frame.shape[1], frame.shape[0]
        image = frame.copy()

        # モデル入力画像生成
        in_width, in_height = 480, 480
        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        image = cv2.resize(image, (in_width, in_height),
                           cv2.INTER_AREA).astype(np.float32)
        image = image.transpose(2, 0, 1)  # [H, W, Ch] → [Ch, H, W]
        image /= 255.0
        image = torch.from_numpy(image.astype(np.float32))
        image = image.to("cuda")

        # モデル推論
        prediction = model(image.unsqueeze(dim=0))
        box = prediction[0]["boxes"].cpu().detach().numpy()

        # 検出結果の妥当性確認
        detection_flag = True
        if len(box) == 0:
            detection_flag = False
        else:
            area = (box[0][2] - box[0][0]) * (box[0][3] - box[0][1])
            if (1000 >= area) or (area >= 7000):
                detection_flag = False

        # 検出BBoxの反映
        if detection_flag:
            box = box[0]
            xmin = int(box[0] / in_width * frame_width)
            ymin = int(box[1] / in_height * frame_height)
            xmax = int(box[2] / in_width * frame_width)
            ymax = int(box[3] / in_height * frame_height)
            cv2.rectangle(frame, (xmin, ymin), (xmax, ymax), (0, 255, 0))
        cv2.imshow("prediction", frame)

        # 視点変換画像
        above_img = cv2.warpPerspective(frame, gui_homography_matrix, dsize=(
            int(480 * gui_ratio_w)+offset, int(480 * gui_ratio_h)+offset))
        cv2.imshow("homography", above_img)
        cv2.waitKey(1)

        # 物体座標[XY座標]
        if detection_flag:
            object_px, object_py = (xmax + xmin) // 2, ymax
            object_pixel = np.array([[object_px, object_py, 1]])
            object_crd = np.dot(crd_homography_matrix,
                                object_pixel.T).reshape(-1)
            object_cx = object_crd[0] / object_crd[2]
            object_cy = object_crd[1] / object_crd[2] - cola_radius / 2
            print(f"X座標{object_cx}, Y座標{object_cy}")

    except KeyboardInterrupt:
        cap.release()
        cv2.destroyAllWindows()
        break
