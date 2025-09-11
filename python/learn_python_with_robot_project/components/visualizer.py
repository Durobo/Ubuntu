# Import lớp TwoLinkArm để lấy thông tin từ nó
from components.two_link_arm import TwoLinkArm

import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import numpy as np

class ArmVisualizer:
    def __init__(self, arm: TwoLinkArm):
        """Khởi tạo visualizer với một đối tượng cánh tay robot."""
        self._arm = arm
        
        # Thiết lập môi trường vẽ của Matplotlib
        self._fig, self._ax = plt.subplots() # Tạo một cửa sổ hình và một hệ trục
        self._ax.set_aspect('equal') # Đảm bảo tỉ lệ x, y bằng nhau

        # Xác định giới hạn của trục vẽ, dựa trên tổng chiều dài cánh tay
        total_length = self._arm.get_link_lengths()[0] + self._arm.get_link_lengths()[1]
        self._ax.set_xlim(-total_length * 1.1, total_length * 1.1)
        self._ax.set_ylim(-total_length * 1.1, total_length * 1.1)
        self._ax.grid(True)
        self._ax.set_title("2-Link Robot Arm Visualization")
        
        # Tạo ra các đường vẽ ban đầu (sẽ được cập nhật sau)
        # 'o-' nghĩa là vẽ điểm tròn (o) nối với nhau bằng đường thẳng (-)
        self._arm_line, = self._ax.plot([], [], 'o-', lw=3, markersize=8)

    def update_plot(self):
        """
        Cập nhật và vẽ lại hình ảnh của cánh tay robot dựa trên
        trạng thái hiện tại của nó.
        """
        # --- Phần tính toán tọa độ để vẽ ---
        # Chúng ta cần tọa độ của 3 điểm: Gốc, Khớp 2, và Đầu cuối
        
        # 1. Tọa độ Gốc
        p0 = np.array([0, 0])
        
        # 2. Tọa độ Khớp 2
        #    Điểm này chính là phần tính toán đầu tiên trong công thức FK
        l1 = self._arm.get_link_lengths()[0]
        theta1_rad = self._arm.get_joint_angles_rad()[0]
        p1 = np.array([l1 * np.cos(theta1_rad), l1 * np.sin(theta1_rad)])

        # 3. Tọa độ Đầu cuối (End-effector)
        p2 = self._arm.get_end_effector_position()
        
        # --- Phần vẽ của Matplotlib ---
        
        # gom các tọa độ x và y lại
        x_coords = [p0[0], p1[0], p2[0]]
        y_coords = [p0[1], p1[1], p2[1]]
        
        # Cập nhật dữ liệu cho đường vẽ
        self._arm_line.set_data(x_coords, y_coords)
        
        # Yêu cầu Matplotlib vẽ lại cửa sổ
        plt.draw()
        plt.pause(0.1) # Dừng một chút để ta có thể thấy hình ảnh