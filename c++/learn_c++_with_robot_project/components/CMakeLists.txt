# Tìm gói Eigen3 trên hệ thống. 'REQUIRED' nghĩa là build sẽ thất bại nếu không tìm thấy.
find_package(Eigen3 REQUIRED)

# Tạo một thư viện có tên là "components"
add_library(components)

# Chỉ định các file sources code (.cpp) cho thư viện này
target_sources(components
    PRIVATE
        src/RobotComponent.cpp
        src/RobotJoint.cpp
        src/Gripper.cpp
        src/Kinematics.cpp
)

# Chỉ định thư mục 'include' là public, để các target khác
# (như app) có thể thấy file .hpp
target_include_directories(components
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Liên kết thư viện 'components' với Eigen.
#CMake sẽ tự động thêm đường dẫn include của Eigen với trình biên dịch
target_link_libraries(components
    PUBLIC
        Eigen3::Eigen
)