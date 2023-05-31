import time
import threading

import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
from aruco_interface.srv import ArmCommand
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint


from control_arm.kinematics import inverse_kinematics, joint_in_range

# ARMパラメーター
DT_OFFSET = 0.5
JOINT_DT = 4
GRIPPER_DT = 0.2
GRIPPER_OPEN = 0
GRIPPER_CLOSE = 0.4
ARM_UP_Z = 0.15
END_POSITION = [0.15, 0.2, ARM_UP_Z, 0.1]


class ControlArm(Node):
    def __init__(self):
        super().__init__("control_arm_node")
        self.joint_names = [
            "crane_plus_joint1",
            "crane_plus_joint2",
            "crane_plus_joint3",
            "crane_plus_joint4"
        ]
        self.crane_name = ["crane_plus_joint_hand"]

        self.publisher_joint = self.create_publisher(
            JointTrajectory,
            "crane_plus_arm_controller/joint_trajectory",
            10
        )
        self.publisher_gripper = self.create_publisher(
            JointTrajectory,
            "crane_plus_gripper_controller/joint_trajectory",
            10
        )

        self.arm_server = self.create_service(
            ArmCommand,
            "myarm/command",
            self.arm_callback
        )

        # jointの初期化
        self.elbow_up = True
        self.initial_gripper = GRIPPER_OPEN
        self.initial_joint = [0.0, 0.0, 0.0, 0.0]
        self.move_joint_gripper(
            self.initial_joint, self.initial_gripper, JOINT_DT)
        self.get_logger().info("initialze ControlArm")

        # Colaの置き場所に向けたJoint
        self.last_joint = inverse_kinematics(END_POSITION, self.elbow_up)

    def publish_joint(self, q, d_time):
        msg = JointTrajectory()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.joint_names = self.joint_names
        msg.points = [JointTrajectoryPoint()]
        msg.points[0].positions = [
            float(q[0]), float(q[1]), float(q[2]), float(q[3])
        ]
        msg.points[0].time_from_start = Duration(
            seconds=int(d_time),
            nanoseconds=(d_time-int(d_time))*1e9
        ).to_msg()
        self.publisher_joint.publish(msg)

    def publish_gripper(self, gripper, d_time):
        msg = JointTrajectory()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.joint_names = ['crane_plus_joint_hand']
        msg.points = [JointTrajectoryPoint()]
        msg.points[0].positions = [float(gripper)]
        msg.points[0].time_from_start = Duration(
            seconds=int(d_time),
            nanoseconds=(d_time-int(d_time))*1e9
        ).to_msg()
        self.publisher_gripper.publish(msg)

    # RobotArmにjointとGripper動作を命令
    def move_joint_gripper(self, joint, gripper, dt):
        self.publish_joint(joint, dt)
        self.publish_gripper(gripper, dt)
        time.sleep(dt+DT_OFFSET)

    # X,Y座標指定の場所のColaを掴む
    def arm_callback(self, request, response):

        arm_y, arm_x, arm_z, arm_pitch = request.colax, request.colay, 0.05, 0.1
        arm_y /= 100  # [cm] → [m]変換
        arm_x /= 100  # [cm] → [m]変換
        arm_y -= 0.005
        arm_x -= 0.026
        joint = inverse_kinematics(
            [arm_x, arm_y, arm_z, arm_pitch], self.elbow_up)

        if (not all(joint_in_range(joint))) or (joint is None):
            response.catchcola = False
        else:

            # 1. アームを物体のところまで動かす
            self.move_joint_gripper(joint, GRIPPER_OPEN, JOINT_DT)

            # 2. Gripperを閉める
            self.move_joint_gripper(joint, GRIPPER_CLOSE, GRIPPER_DT)

            # 3. 真上にアームを動かす
            joint = inverse_kinematics([arm_x, arm_y, ARM_UP_Z, arm_pitch], self.elbow_up)
            self.move_joint_gripper(joint, GRIPPER_CLOSE, JOINT_DT-2)

            # 4. アームを物体置き場のところまで動かす
            self.move_joint_gripper(self.last_joint, GRIPPER_CLOSE, JOINT_DT-2)

            # 5. アームを物体置き場のところで物体を落とす
            self.move_joint_gripper(self.last_joint, GRIPPER_OPEN, GRIPPER_DT)

            # 6. アームを初期位置まで動かす
            self.move_joint_gripper(
                self.initial_joint, self.initial_gripper, JOINT_DT)
            response.catchcola = True

        return response


def main():

    rclpy.init()
    control_arm_node = ControlArm()
    try:
        thread = threading.Thread(target=rclpy.spin, args=(control_arm_node,))
        thread.start()
    except KeyboardInterrupt:
        rclpy.shutdown()
