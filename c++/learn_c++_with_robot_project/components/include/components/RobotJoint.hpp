#ifndef ROBOT_JOINT_HPP
#define ROBOT_JOINT_HPP

#include "RobotComponent.hpp"
#include <string>

class RobotJoint : public RobotComponent {
    public:
        // Hàm tạo (Constructor) của lớp con.
        RobotJoint(int id, const std::string& name, double angle_limit);

        // Method thiết lập góc.
        void setAngle(double angle);

        // Method lấy giá trị góc hiện tại.
        // "const" ở cuối nghĩa là phương thức này không làm thay đổi trạng thái của đối tượng.
        double getAngle() const;

        // Method thiết lập tốc độ.
        void setVelocity(double velocity);

        // Method lấy tốc độ.
        double getVelocity() const;
        
        // In trạng thái và tốc độ ra màn hình.
        // Ghi đè (Override) phương thức của lớp cha để lấy thêm thông tin riêng.
        void printStatus() const override;

    private:
        double m_angle_deg; // Góc hiện tại, tính bằng độ.
        double m_angle_limit_deg; // Giới hạn góc.
        double m_velocity_dps; // Tốc độ hiện tại.
};

#endif