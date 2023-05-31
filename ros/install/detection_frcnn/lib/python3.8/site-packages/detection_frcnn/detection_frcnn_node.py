import cv2
import numpy as np
from PIL import Image as IMG
from pathlib import Path

import torch
import torchvision
from torchvision.models.detection.faster_rcnn import FastRCNNPredictor

import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from aruco_interface.srv import ColaCommand
from rclpy.qos import qos_profile_sensor_data
from ament_index_python.packages import get_package_prefix

# 定数
JACCARD_THRESHOLD = 0.95

# プロジェクトディレクトリの探索
package = str(Path(__file__).resolve().parent.name)
workspace = Path(get_package_prefix(package)).parents[1]
path_workspace = workspace / "src" / package


class DetectionFrcnn(Node):
    def __init__(self):
        super().__init__("detection_frcnn_node")

        # カメラ画像サブスクライバー
        self.subscription = self.create_subscription(
            Image,
            "/image_raw",
            self.image_callback,
            qos_profile_sensor_data
        )

        # 検出結果パブリッシャー
        self.list_counter = 0
        self.send_list = [-1, -1, -1, -1]
        self.cola_server = self.create_service(
            ColaCommand,
            "cola/command",
            self.cola_callback
        )

        # Image→cv2
        self.br = CvBridge()

        # モデル読み込み
        num_classes = 2
        self.model = torchvision.models.detection.fasterrcnn_resnet50_fpn()
        in_features = self.model.roi_heads.box_predictor.cls_score.in_features
        self.model.roi_heads.box_predictor = FastRCNNPredictor(
            in_features, num_classes)
        self.model.load_state_dict(torch.load(
            path_workspace / "pth_model/faster_rcnn.pth"))
        self.model = self.model.to("cuda")
        self.model.eval()

        # gifデータ保存
        self.gif_list = []

    def image_callback(self, data):

        # 画像取得
        frame = self.br.imgmsg_to_cv2(data, "bgr8")
        frame_width, frame_height = frame.shape[1], frame.shape[0]
        image = frame.copy()

        # 画像のモデル入力用変換
        image_width, image_height = 480, 480
        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        image = cv2.resize(image, (image_width, image_height),
                           cv2.INTER_AREA).astype(np.float32)
        image = image.transpose(2, 0, 1)  # [H, W, Ch] → [Ch, H, W]
        image /= 255.0
        image = torch.from_numpy(image.astype(np.float32))
        image = image.to("cuda")

        # モデル推論
        prediction = self.model(image.unsqueeze(dim=0))
        box = prediction[0]["boxes"].cpu().detach().numpy()
        if len(box) != 0:
            box = box[0]
            xmin = int(box[0] / image_width * frame_width)
            ymin = int(box[1] / image_height * frame_height)
            xmax = int(box[2] / image_width * frame_width)
            ymax = int(box[3] / image_height * frame_height)
            self.set_list([xmin, ymin, xmax, ymax])
            cv2.rectangle(frame, (xmin, ymin), (xmax, ymax), (0, 255, 0))
        else:
            self.initialize_list()

        pil_frame = IMG.fromarray(frame)
        self.gif_list.append(pil_frame)
        cv2.imshow("ObjectDetection", frame)
        cv2.waitKey(1)

    def initialize_list(self):
        self.list_counter = 0
        self.send_list = [-1, -1, -1, -1]

    def set_list(self, send_list):

        # 今回の検出結果
        xmin, ymin = send_list[0], send_list[1]
        xmax, ymax = send_list[2], send_list[3]
        box = [xmin, ymin, xmax, ymax]

        # 前回の検出結果
        pre_xmin, pre_ymin = self.send_list[0], self.send_list[1]
        pre_xmax, pre_ymax = self.send_list[2], self.send_list[3]
        pre_box = [pre_xmin, pre_ymin, pre_xmax, pre_ymax]

        # 誤差が閾値以内の判定
        jaccard = self.get_jaccard(box, pre_box)
        if jaccard >= JACCARD_THRESHOLD:
            self.list_counter += 1
        else:
            self.list_counter = 0

        # 送信内容の更新
        self.send_list = send_list.copy()

    def get_jaccard(self, box1, box2):

        # 検出BBox結果1
        box1_xmin, box1_ymin = box1[0], box1[1]
        box1_xmax, box1_ymax = box1[2], box1[3]

        # 検出BBox結果2
        box2_xmin, box2_ymin = box2[0], box2[1]
        box2_xmax, box2_ymax = box2[2], box2[3]

        # 共通領域の幅・高さ・面積
        common_w = min(box2_xmax, box1_xmax) - max(box2_xmin, box1_xmin)
        common_h = min(box2_ymax, box1_ymax) - max(box2_ymin, box1_ymin)
        common_area = max(common_w, 0) * max(common_h, 0)

        # Box1, 2での面積
        box1_area = (box1_xmax - box1_xmin) * (box1_ymax - box1_ymin)
        box2_area = (box2_xmax - box2_xmin) * (box2_ymax - box2_ymin)

        # Jaccard係数算出
        if (box1_area + box2_area - common_area) == 0:
            jaccard = 0
        else:
            jaccard = common_area / (box1_area + box2_area - common_area)
        return jaccard

    def cola_callback(self, request, response):

        # 検知回数が10回以上
        if self.list_counter >= 10:
            response.xmin = int(self.send_list[0])
            response.ymin = int(self.send_list[1])
            response.xmax = int(self.send_list[2])
            response.ymax = int(self.send_list[3])
            return response

        # 検知回数が10回以内
        else:
            response.xmin = -1
            response.ymin = -1
            response.xmax = -1
            response.ymax = -1
            return response
        
    def write_gif(self, out_filename="ObjectDetection.gif"):
        print("write Gif")
        self.gif_list[0].save(out_filename, save_all=True, append_images=self.gif_list[1:], optimize=False, duration=100, loop=0)


def main():
    rclpy.init()
    detection_frcnn_node = DetectionFrcnn()
    try:
        rclpy.spin(detection_frcnn_node)
    except KeyboardInterrupt:
        detection_frcnn_node.write_gif()
    else:
        detection_frcnn_node.write_gif()
    rclpy.shutdown()

