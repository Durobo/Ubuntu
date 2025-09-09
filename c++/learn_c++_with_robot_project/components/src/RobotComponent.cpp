#include "components/RobotComponent.hpp"
#include <iostream>

RobotComponent::RobotComponent(int id, const std::string& name)
    : m_id(id), m_name(name) {}

int RobotComponent::getID() const {
    return m_id;
}

const std::string& RobotComponent::getName() const {
    return m_name;
}

void RobotComponent::printStatus() const {
    // In ra thông tin chung
    std::cout << "Component [ID: " << m_id << ", Name: " << m_name << "]: ";
}