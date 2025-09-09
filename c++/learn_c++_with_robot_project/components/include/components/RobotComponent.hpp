#ifndef ROBOT_COMPONENT_HPP
#define ROBOT_COMPONENT_HPP

#include <string>

class RobotComponent {
    public:
        // Constructor cho lớp cha.
        RobotComponent(int id, const std::string& name);

        virtual ~RobotComponent() = default;
        
        int getID() const;

        // Thiết lập trả về const reference để hiệu quả hơn. 
        const std::string& getName() const;

        virtual void printStatus() const;
    
    protected:
        int m_id;
        std::string m_name;
};

#endif