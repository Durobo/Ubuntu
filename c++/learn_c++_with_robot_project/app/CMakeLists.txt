# Tạo một file thực thi tên là "my_robot_app" từ file main.cpp
add_executable(my_robot_app main.cpp)

# Đây là bước kết nối: Liên kết file thực thi 'my_robot_app'
# với thư viện 'components'.
# Điều này cho phép 'main.cpp' sử dụng được các lớp từ thư viện.
target_link_libraries(my_robot_app PRIVATE components)