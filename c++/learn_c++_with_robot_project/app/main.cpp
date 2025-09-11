#include "components/RobotJoint.hpp" 
#include "components/Gripper.hpp"
#include "components/Kinematics.hpp"
#include "components/TwoLinkArm.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    // Sử dụng smart pointers để quản lý bộ nhớ tự động. 
    std::vector<std::unique_ptr<RobotComponent>> robot_arm;

    // Thêm các thành phần vào cánh tay robot.
    robot_arm.push_back(std::make_unique<RobotJoint>(1, "shoulder_pan", 180.0));
    robot_arm.push_back(std::make_unique<RobotJoint>(2, "shoulder_lift", 150.0));
    robot_arm.push_back(std::make_unique<RobotJoint>(3, "elbow", 150.0));
    robot_arm.push_back(std::make_unique<Gripper>(4, "hand_e_gripper"));

    // Thao tác với thành phần riêng lẻ trong lớp con.
    // Cần phải downcast để truy cập phương thức của lớp con.
    // dynamic_cast là cách an toàn để làm việc này.
    RobotJoint* elbow_joint = dynamic_cast<RobotJoint*>(robot_arm[2].get());
    if (elbow_joint) {
        elbow_joint->setAngle(90.0);
    }
    
    Gripper* gripper = dynamic_cast<Gripper*>(robot_arm[3].get());
    if (gripper) {
        gripper->close();
        gripper->setForce(25.0);
    }

    // In ra trạng thái các phần tử.
    std::cout << "\n--- Full Robot Status ---\n";

    for (const auto& component : robot_arm) {
        component->printStatus();
    }    

    std::cout << "\nProgram finished. Components will be automatically deallocated.\n";

    // Code test class Kinematics
    std::cout << "\n--- Kinematics Test ---\n";
    Kinematics mobile_base_pose(1.0, 2.0, 0.785); // 0.785 rad ~ 45 deg
    
    mobile_base_pose.printPose();
    
    std::cout << "Moving robot...\n";
    mobile_base_pose.move(0.5, -0.2);

    mobile_base_pose.printPose();

    // TwoLinkArm 
    std::cout << "\n--- Two-Link Arm FK Test ---\n";
    TwoLinkArm arm(10.0, 7.0); // L1=10, L2=7

    std::cout << "\n* Case 1: (0, 0) deg\n";
    arm.setJointAngles(0, 0);
    arm.printStatus();

    std::cout << "\n* Case 2: (90, 0) deg\n";
    arm.setJointAngles(90, 0);
    arm.printStatus();

    std::cout << "\n* Case 3: (90, -90) deg\n";
    arm.setJointAngles(90, -90);
    arm.printStatus();

    return 0;
}