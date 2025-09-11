#ifndef TWOLINKARM_HPP
#define TWOLINKARM_HPP

#include "components/RobotJoint.hpp" // Dùng lại lớp RobotJoint
#include <Eigen/Dense>               // Dùng cho tọa độ
#include <memory>                    // Dùng cho unique_ptr

class TwoLinkArm {
    public:
        // Constructor nhận vào chiều dài của 2 link
        TwoLinkArm(double link1_length, double link2_length);

        // Đặt góc cho các khớp (lưu ý đơn vị là ĐỘ)
        void setJointAngles(double theta1_deg, double theta2_deg);

        // Tính toán và trả về vị trí đầu cuối (end-effector)
        Eigen::Vector2d getEndEffectorPosition() const;

        // In trạng thái của toàn bộ cánh tay
        void printStatus() const;

    private:
        double m_l1; // Chiều dài link 1
        double m_l2; // Chiều dài link 2

        // Composition: TwoLinkArm "có" (has-a) hai RobotJoint
        std::unique_ptr<RobotJoint> m_joint1;
        std::unique_ptr<RobotJoint> m_joint2;
};

#endif