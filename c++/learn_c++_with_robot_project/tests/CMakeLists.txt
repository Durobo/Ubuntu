# Tạo một file thực thi cho bài test
add_executable(kinematics_test test_kinematics.cpp)

# Liên kết bài test với thư viện `components` (để nó có thể sử dụng lớp Kinematics)
target_link_libraries(kinematics_test
    PRIVATE
        components
        GTest::gtest_main # <-- Liên kết với Google Test
)

# Thêm bài test này vào bộ quản lý test của CMake
include(GoogleTest)
gtest_discover_tests(kinematics_test)