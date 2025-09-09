# Chuẩn Compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Thêm file 'compile_commands.json'
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Đặt phiên bản tối thiểu cho CMake.
cmake_minimum_required(VERSION 3.10)

# Khai báo tên và phiên bản dự án.
project(RoboticsProject VERSION 1.0)

# Thêm thư mục con chứa các thư viện và tệp thực thi.
add_subdirectory(components)
add_subdirectory(app)

# Đơn vị kiểm thử (Unit Testing) với Google Test.
# Tải GoogleTest về
include(GoogleTest.cmake)

# Thêm một thư mục mới cho các bài test
add_subdirectory(tests)