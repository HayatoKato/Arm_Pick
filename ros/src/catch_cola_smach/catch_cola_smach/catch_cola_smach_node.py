import numpy as np
from time import sleep

import smach
import rclpy

from rclpy.node import Node
from aruco_interface.srv import ArucoCommand, ColaCommand, AxisCommand, ArmCommand

# ArUco間距離情報
ar_width = 29.0  # [cm]
ar_height = 30.8  # [cm]
arm_ar0 = 16.5  # [cm]
arm_ar1 = 12.4  # [cm]
gui_ratio_w = ar_width/ar_height  # マーカー間比率 [幅]
gui_ratio_h = ar_height/ar_width  # マーカー間比率 [高さ]


class CatchColaSmach(Node):

    def __init__(self):
        super().__init__("catch_cola_smach_node")

    def execute(self):
        sm = smach.StateMachine(outcomes=["succeeded"])

        with sm:
            smach.StateMachine.add(
                "DETECT_ARUCO",
                DetectArucoState(self),
                {"succeeded": "DETECT_COLA", "failed": "DETECT_ARUCO"}
            )

            smach.StateMachine.add(
                "DETECT_COLA",
                DetectColaState(self),
                {"succeeded": "TRANSFORM_AXIS", "failed": "DETECT_COLA"}
            )

            smach.StateMachine.add(
                "TRANSFORM_AXIS",
                TransformAxisState(self),
                {"succeeded": "CONTROL_ARM", "failed": "DETECT_COLA"}
            )

            smach.StateMachine.add(
                "CONTROL_ARM",
                ControlArmState(self),
                {"succeeded": "DETECT_COLA", "failed": "DETECT_COLA"}
            )
        sm.execute()


def main():
    rclpy.init()
    node = CatchColaSmach()
    node.execute()


class DetectArucoState(smach.State):
    def __init__(self, node):
        smach.State.__init__(
            self,
            output_keys=["aruco_pixels"],
            outcomes=["succeeded", "failed"]
        )

        # ノード情報
        self.node = node
        self.logger = self.node.get_logger()

        # Aruco検出用Client
        self.aruco_client = self.node.create_client(
            ArucoCommand,
            "aruco/command"
        )

        # サービス通信接続
        while not self.aruco_client.wait_for_service(timeout_sec=1.0):
            self.logger.info("DetectArucoサービスの接続待ちです・・・")
        self.request = ArucoCommand.Request()

    def execute(self, userdata):

        # リクエストの送信
        sleep(1)
        self.logger.info("Arucoの状態を開始します")
        self.request.command = "start"
        self.future = self.aruco_client.call_async(self.request)

        # レスポンスの受信待ち
        while rclpy.ok():
            rclpy.spin_once(self.node)
            if self.future.done():
                response = self.future.result()
                break

        # ArUco座標リスト
        aruco_result = [
            [response.ar0x, response.ar0y],
            [response.ar1x, response.ar1y],
            [response.ar2x, response.ar2y],
            [response.ar3x, response.ar3y],
        ]

        if [-1, -1] not in aruco_result:
            self.logger.info("Arucoの検出完了")
            userdata.aruco_pixels = aruco_result
            return "succeeded"
        else:
            self.logger.info("Arucoの検出失敗")
            return "failed"


class DetectColaState(smach.State):
    def __init__(self, node):
        smach.State.__init__(
            self,
            output_keys=["cola_pixels"],
            outcomes=["succeeded", "failed"]
        )

        # ノード情報
        self.node = node
        self.logger = self.node.get_logger()

        # Cola検出用Clinet
        self.cola_client = self.node.create_client(
            ColaCommand,
            "cola/command"
        )

        # サービス通信接続
        while not self.cola_client.wait_for_service(timeout_sec=1.0):
            self.logger.info("DetectColaサービスの接続待ちです・・・")
        self.request = ColaCommand.Request()

    def execute(self, userdata):

        # リクエストの送信
        self.logger.info("Colaの検出を行います")
        self.request.command = "start"
        self.future = self.cola_client.call_async(self.request)

        # レスポンスの受信待ち
        while rclpy.ok():
            rclpy.spin_once(self.node)
            if self.future.done():
                response = self.future.result()
                break

        # Cola座標リスト
        cola_result = [
            [response.xmin, response.ymin],
            [response.xmax, response.ymax]
        ]

        if -1 not in np.array(cola_result).reshape(-1):
            userdata.cola_pixels = cola_result
            return "succeeded"
        else:
            return "failed"


class TransformAxisState(smach.State):
    def __init__(self, node):
        smach.State.__init__(
            self,
            input_keys=["aruco_pixels", "cola_pixels"],
            output_keys=["cola_xy"],
            outcomes=["succeeded", "failed"]
        )

        # ノード情報
        self.node = node
        self.logger = self.node.get_logger()

        # Axis変換Clinet
        self.axis_client = self.node.create_client(
            AxisCommand,
            "axis/command"
        )

        # サービス通信接続
        while not self.axis_client.wait_for_service(timeout_sec=1.0):
            self.logger.info("TransformAxisサービスの接続待ちです・・・")
        self.request = AxisCommand.Request()

    def execute(self, userdata):

        # リクエストの送信
        self.logger.info("Colaの座標計算を行います")
        self.request.ar0x, self.request.ar0y = userdata.aruco_pixels[0]
        self.request.ar1x, self.request.ar1y = userdata.aruco_pixels[1]
        self.request.ar2x, self.request.ar2y = userdata.aruco_pixels[2]
        self.request.ar3x, self.request.ar3y = userdata.aruco_pixels[3]
        self.request.xmin, self.request.ymin = userdata.cola_pixels[0]
        self.request.xmax, self.request.ymax = userdata.cola_pixels[1]
        self.future = self.axis_client.call_async(self.request)

        # レスポンスの受信待ち
        while rclpy.ok():
            rclpy.spin_once(self.node)
            if self.future.done():
                response = self.future.result()
                break

        # ColaXY座標リスト
        x, y = response.colax, response.colay
        if ((-arm_ar1 <= x) and (x <= arm_ar0)) and ((0 <= y) and (x <= ar_height)):
            userdata.cola_xy = [x, y]
            self.logger.info(f"X座標{x}, Y座標{y}")
            return "succeeded"
        else:
            return "failed"


class ControlArmState(smach.State):
    def __init__(self, node):
        smach.State.__init__(
            self,
            input_keys=["cola_xy"],
            outcomes=["succeeded", "failed"]
        )

        # ノード情報
        self.node = node
        self.logger = self.node.get_logger()

        # ロボットアーム制御用Clinet
        self.arm_client = self.node.create_client(
            ArmCommand,
            "myarm/command"
        )

        # サービス通信接続
        while not self.arm_client.wait_for_service(timeout_sec=1.0):
            self.logger.info("ControlArmサービスの接続待ちです・・・")
        self.request = ArmCommand.Request()

    def execute(self, userdata):

        # リクエストの送信
        self.logger.info("ARMの制御を行います")
        self.request.colax, self.request.colay = userdata.cola_xy
        self.future = self.arm_client.call_async(self.request)

        # レスポンスの受信待ち
        while rclpy.ok():
            rclpy.spin_once(self.node)
            if self.future.done():
                response = self.future.result()
                break

        # ColaXY座標リスト
        catchcola = response.catchcola
        if catchcola:
            return "succeeded"
        else:
            return "failed"
