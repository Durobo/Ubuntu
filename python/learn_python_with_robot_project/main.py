from components.joint import RobotJoint
from components.gripper import Gripper
from components.kinematics import Kinematics
from components.two_link_arm import TwoLinkArm
from components.visualizer import ArmVisualizer
import time
import matplotlib.pyplot as plt

def main():
    robot_arm = [
        RobotJoint(1, "shouder_pan", 180.0),
        RobotJoint(2, "shouder_lift", 150.0),
        RobotJoint(3, "elbow", 150.0),
        Gripper(4, "hand_e_gripper")
    ]

    robot_arm[1].set_angle(90.0)
    robot_arm[3].close()
    robot_arm[3].set_force(25.0)
    
    # In ra cac phan robot_arm
    print("\n--- Full Robot Status ---\n")

    for component in robot_arm:
        component.print_status();    
    
    print("\nProgram finished. Components will be automatically deallocated.\n")

    # Test class Kinematics
    print("\n--- Kinematics Test ---\n")

    mobile_base_pose = Kinematics(1.0, 2.0, 0.785)
    mobile_base_pose.print_pose()

    # Test class TwoLinkArm
    print("\n--- Two-Link Arm FK Test ---\n")

    arm = TwoLinkArm(10.0, 7.0)
    
    print("\n* Case 1: (0, 0) deg\n")
    arm.set_joint_angles(0, 0)
    arm.print_status()

    print("\n* Case 3: (90, -90) deg\n")
    arm.set_joint_angles(90, -90)
    arm.print_status()

    # 2. Tạo đối tượng visualizer, liên kết nó với robot
    visualizer = ArmVisualizer(arm)

    # 3. Tạo một chuỗi các vị trí mà chúng ta muốn robot di chuyển tới
    target_angles_deg = [
        (0, 0),
        (30, 20),
        (60, 40),
        (90, 60),
        (90, 0),
        (90, -90),
        (45, -45),
        (0, 0),
    ]

    print("Starting robot arm animation...")
    
    # Vòng lặp để tạo hoạt ảnh
    for theta1, theta2 in target_angles_deg:
        print(f"Moving to: ({theta1}, {theta2})")
        arm.set_joint_angles(theta1, theta2)
        visualizer.update_plot()
        time.sleep(1) # Dừng 1 giây để xem

    print("Animation finished. Close the plot window to exit.")
    plt.show(block=True) # Giữ cho cửa sổ đồ thị không bị tắt ngay

if __name__ == "__main__":
    main()