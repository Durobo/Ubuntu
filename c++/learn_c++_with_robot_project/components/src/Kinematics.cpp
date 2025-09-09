#include "components/Kinematics.hpp"
#include <iostream>

Kinematics::Kinematics(double x, double y, double theta_rad) {
    m_pose << x, y, theta_rad;
}

void Kinematics::move(double dx, double dy) {
    m_pose(0) += dx; 
    m_pose(1) += dy; 
}

void Kinematics::printPose() const {
    std::cout << "Robot Pose (x, y, theta): [" 
              << m_pose(0) << ", " 
              << m_pose(1) << ", " 
              << m_pose(2) << "]\n";
}

Eigen::Vector3d Kinematics::getPose() const {
    return m_pose;
}