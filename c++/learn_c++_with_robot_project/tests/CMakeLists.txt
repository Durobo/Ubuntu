# Tạo một file thực thi cho bài test
add_executable(robot_test test_my_robot.cpp)

# Liên kết bài test với thư viện `components` (để nó có thể sử dụng lớp Kinematics)
target_link_libraries(robot_test
    PRIVATE
        components
        GTest::gtest_main # <-- Liên kết với Google Test
)

# Thêm bài test này vào bộ quản lý test của CMake
include(GoogleTest)
gtest_discover_tests(robot_test)