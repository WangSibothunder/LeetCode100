import math
import numpy as np
import matplotlib.pyplot as plt

# 设置中文字体支持
plt.rcParams['font.sans-serif'] = ['SimHei', 'Arial Unicode MS', 'DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False

# 定义数据点范围 (N值)
N = np.arange(2, 1024, 1)

# 计算DFT的复杂度 O(N^2)
DFT_complexity = N ** 2

# 计算FFT的复杂度 O(N log N)
FFT_complexity = N/2 * np.log2(N)
for i in range(2,len(FFT_complexity)):
    if(math.log2(i)%2!=0):
        upper_n = pow(2, (int(math.log2(i))+1))
        FFT_complexity[i] = upper_n * (int(math.log2(i))+1)

# 创建图形
plt.figure(figsize=(10, 6))

# 绘制DFT和FFT复杂度曲线
plt.plot(N, DFT_complexity, label='DFT O(N²)', color='red')
plt.plot(N, FFT_complexity, label='FFT O(N/2 log N)', color='blue')

# 添加标题和标签
plt.title('DFT 与 FFT 计算复杂度对比')
plt.xlabel('输入大小 N')
plt.ylabel('运算次数')
plt.legend()
plt.grid(True, alpha=0.3)

# 设置对数刻度以更好地显示差异
plt.yscale('log')

# 显示图形
plt.tight_layout()
plt.show()