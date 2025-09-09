#include "components/RobotJoint.hpp"
#include <iostream>

RobotJoint::RobotJoint(int id, const std::string& name, double angle_limit)
    : RobotComponent(id, name), // GỌI CONSTRUCTOR LỚP CHA.
    m_angle_deg(0.0),
    m_angle_limit_deg(angle_limit),
    m_velocity_dps(0.0) 
{
    std::cout << "Joint '" << m_name << "' created." << std::endl;
}

void RobotJoint::setAngle(double angle) {
    // Bảo vệ dữ liệu, chỉ chấp nhận giá trị trong limit.
    if (angle > m_angle_limit_deg) {
        m_angle_deg = m_angle_limit_deg;
        std::cout << "Warning: Angle for " << m_name << " exceeds limit. Clamped to " << m_angle_limit_deg << std::endl;
    } 
    else if (angle < -m_angle_limit_deg) {
        m_angle_deg = -m_angle_limit_deg;
        std::cout << "Warning: Angle for " << m_name << " exceeds limit. Clamped to " << -m_angle_limit_deg << std::endl;
    } 
    else {
        m_angle_deg = angle;
    }
}

double RobotJoint::getAngle() const {
    return m_angle_deg;
}

void RobotJoint::setVelocity(double velocity) {
    m_velocity_dps = velocity;
}

double RobotJoint::getVelocity() const {
    return m_velocity_dps;
}

// Định nghĩa hàm printStatus() bị ghi đè.
void RobotJoint::printStatus() const {
    RobotComponent::printStatus(); // Gọi hàm của lớp cha để in thông tin chung.

    // In thông tin riêng.
    std::cout << "Joint [" << m_name << "]: Pos = " << m_angle_deg << " deg, Vel = " << m_velocity_dps << " dps\n";
}