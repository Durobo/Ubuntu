#include "components/TwoLinkArm.hpp"
#include <cmath>     // Για sin, cos
#include <iostream>

// Hàm chuyển độ sang radian
constexpr double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

TwoLinkArm::TwoLinkArm(double link1_length, double link2_length)
    : m_l1(link1_length), m_l2(link2_length) {
    // Giới hạn góc tùy ý, ví dụ 180 độ cho cả 2 khớp
    m_joint1 = std::make_unique<RobotJoint>(1, "base_joint", 180.0);
    m_joint2 = std::make_unique<RobotJoint>(2, "elbow_joint", 180.0);
    std::cout << "Two-Link Arm created with L1=" << m_l1 << ", L2=" << m_l2 << std::endl;
}

void TwoLinkArm::setJointAngles(double theta1_deg, double theta2_deg) {
    m_joint1->setAngle(theta1_deg);
    m_joint2->setAngle(theta2_deg);
}

Eigen::Vector2d TwoLinkArm::getEndEffectorPosition() const {
    // Lấy giá trị góc từ các đối tượng joint
    double theta1_rad = degreesToRadians(m_joint1->getAngle());
    double theta2_rad = degreesToRadians(m_joint2->getAngle());

    // Áp dụng công thức Forward Kinematics
    double x = m_l1 * std::cos(theta1_rad) + m_l2 * std::cos(theta1_rad + theta2_rad);
    double y = m_l1 * std::sin(theta1_rad) + m_l2 * std::sin(theta1_rad + theta2_rad);

    Eigen::Vector2d position;
    position << x, y;
    return position;
}

void TwoLinkArm::printStatus() const {
    m_joint1->printStatus();
    m_joint2->printStatus();
    Eigen::Vector2d ee_pos = getEndEffectorPosition();
    std::cout << "End-Effector at: (x=" << ee_pos.x() << ", y=" << ee_pos.y() << ")\n";
}