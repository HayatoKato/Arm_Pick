import cv2
import numpy as np

import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
from catch_cola_interface.srv import AxisCommand

# Cola情報
cola_radius = 2.5  # [cm]

# ArUco間距離情報
ar_width = 29.0  # [cm]
ar_height = 30.8  # [cm]
arm_ar0 = 16.5  # [cm]
arm_ar1 = 12.4  # [cm]
gui_ratio_w = ar_width/ar_height  # マーカー間比率 [幅]
gui_ratio_h = ar_height/ar_width  # マーカー間比率 [高さ]


class TransformationAxis(Node):
    def __init__(self):
        super().__init__("transformation_axis_node")

        # カメラ画像サブスクライバー
        self.image_subscription = self.create_subscription(
            Image,
            "/image_raw",
            self.image_callback,
            qos_profile_sensor_data
        )

        # Aruco/Cola検出結果サーバー
        self.send_list = [-1, -1]
        self.axis_server = self.create_service(
            AxisCommand,
            "axis/command",
            self.axis_callback
        )

        # Image→cv2
        self.br = CvBridge()

        # 射影行列
        self.gui_homography_matrix = None
        self.crd_homography_matrix = None

    def image_callback(self, data):

        # 画像取得
        frame = self.br.imgmsg_to_cv2(data, "bgr8")

        # 視点変換画像
        if self.gui_homography_matrix is not None:
            gui_offset = 10
            gui_w = int(480 * gui_ratio_w)+gui_offset
            gui_h = int(480 * gui_ratio_h)+gui_offset
            gui_img = cv2.warpPerspective(
                frame, self.gui_homography_matrix, dsize=(gui_w, gui_h))

            gui_img = cv2.resize(gui_img, (int(gui_w*1.5), int(gui_h*1.5)), cv2.INTER_CUBIC)
            cv2.imshow("homography", gui_img)
            cv2.waitKey(1)

    def axis_callback(self, request, response):

        # リクエスト信号
        ar_pixel = np.array([[request.ar1x, request.ar1y],
                             [request.ar0x, request.ar0y],
                             [request.ar3x, request.ar3y],
                             [request.ar2x, request.ar2y]
                             ], dtype=np.float32)
        object_pxmin, _ = request.xmin, request.ymin
        object_pxmax, object_pymax = request.xmax, request.ymax

        # 投影行列[GUI用]
        gui_destination = np.array([[0, 0],
                                    [int(480 * gui_ratio_w), 0],
                                    [int(480 * gui_ratio_w),
                                     int(480 * gui_ratio_h)],
                                    [0, int(480 * gui_ratio_h)]], dtype=np.float32)
        self.gui_homography_matrix = cv2.getPerspectiveTransform(
            ar_pixel, gui_destination)

        # 投影行列[座標変換用]
        crd_destination = np.array([[-arm_ar1, 0],
                                    [arm_ar0, 0],
                                    [arm_ar0, ar_height],
                                    [-arm_ar1, ar_height]], dtype=np.float32)
        self.crd_homography_matrix = cv2.getPerspectiveTransform(
            ar_pixel, crd_destination)

        # 物体座標[XY座標]
        object_px, object_py = (object_pxmax + object_pxmin) // 2, object_pymax
        object_pixel = np.array([[object_px, object_py, 1]])
        object_crd = np.dot(self.crd_homography_matrix,
                            object_pixel.T).reshape(-1)
        object_cx = object_crd[0] / object_crd[2]
        object_cy = object_crd[1] / object_crd[2] - cola_radius / 2

        # レスポンス信号作成
        response.colax = object_cx
        response.colay = object_cy
        return response


def main():
    rclpy.init()
    detection_aruco_node = TransformationAxis()
    try:
        rclpy.spin(detection_aruco_node)
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()
