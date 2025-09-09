#ifndef GRIPPER_HPP
#define GRIPPER_HPP

#include "RobotComponent.hpp"

class Gripper : public RobotComponent {
    public:
        Gripper(int id, const std::string& name);

        // Hàm điều khiển.
        void open();

        void close();

        // Hàm thiết lập, lấy giá trị.
        void setForce(double force);

        double getForce() const;

        // Hàm ghi đè.
        void printStatus() const override;

    private:
        bool m_is_open;
        double m_force_newton;
};

#endif