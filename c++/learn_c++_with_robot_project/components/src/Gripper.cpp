#include "components/Gripper.hpp"
#include <iostream>
#include <string>

Gripper::Gripper(int id, const std::string& name)
    : RobotComponent(id, name),
    m_is_open(true),
    m_force_newton(0.0) {}

void Gripper::open() {
    m_is_open = true;
}

void Gripper::close() {
    m_is_open = false;
}

void Gripper::setForce(double force) {
    m_force_newton = force;
}

double Gripper::getForce() const {
    return m_force_newton;
}

void Gripper::printStatus() const {
    RobotComponent::printStatus();
    
    std::string state = m_is_open ? "Open" : "Close";
    std::cout << "State: " << state << "\n" << "Force: " << m_force_newton << " N\n";
}