import cv2

import rclpy
from rclpy.node import Node
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
from aruco_interface.srv import ArucoCommand


class DetectionArUco(Node):
    def __init__(self):
        super().__init__("detection_aruco_node")

        # カメラ画像サブスクライバー
        self.image_subscription = self.create_subscription(
            Image,
            "/image_raw",
            self.image_callback,
            qos_profile_sensor_data
        )

        # ArUco検出サーバー
        self.send_list = [-1, -1, -1, -1, -1, -1, -1, -1]
        self.aruco_server = self.create_service(
            ArucoCommand,
            "aruco/command",
            self.aruco_callback
        )

        # Image→cv2
        self.br = CvBridge()

        # ArUco検出用モデル
        self.ar_pixels = dict.fromkeys(["0", "1", "2", "3"], 0)
        self.dictionary = cv2.aruco.getPredefinedDictionary(
            cv2.aruco.DICT_4X4_50)
        self.parameters = cv2.aruco.DetectorParameters()
        self.detector = cv2.aruco.ArucoDetector(
            self.dictionary, self.parameters)
        self.get_logger().info("initialze DetectionArUco")

    def image_callback(self, data):

        # 画像取得
        frame = self.br.imgmsg_to_cv2(data, "bgr8")

        # ARマーカー認識
        corners, ids, _ = self.detector.detectMarkers(frame)

        # ARマーカー座標取得
        if ids is not None:
            for n, id in enumerate(ids):
                if (id[0] in [0, 1, 2, 3]):
                    self.ar_pixels[str(id[0])] = list(corners[n][0][0])

        # ARマーカー取得情報表示
        for key, value in self.ar_pixels.items():
            if value != 0:
                cx, cy = int(value[0]), int(value[1])
                cv2.circle(frame, (cx, cy), 3, (0, 0, 255))
                self.send_list[int(key) * 2:int(key) * 2+2] = value

        cv2.imshow("ArUco", frame)
        cv2.waitKey(1)

    def aruco_callback(self, request, response):

        # Aruco検出した座標を送る
        response.ar0x = int(self.send_list[0])
        response.ar0y = int(self.send_list[1])
        response.ar1x = int(self.send_list[2])
        response.ar1y = int(self.send_list[3])
        response.ar2x = int(self.send_list[4])
        response.ar2y = int(self.send_list[5])
        response.ar3x = int(self.send_list[6])
        response.ar3y = int(self.send_list[7])
        return response


def main():
    rclpy.init()
    detection_aruco_node = DetectionArUco()
    try:
        rclpy.spin(detection_aruco_node)
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()
