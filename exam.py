import numpy as np
import matplotlib.pyplot as plt

# 设置中文字体（兼容 Windows / macOS / Linux）
plt.rcParams["font.sans-serif"] = ["SimHei", "Microsoft YaHei", "DejaVu Sans"]
plt.rcParams["axes.unicode_minus"] = False

# 实验数据
VB = np.array([2.319, 2.422, 2.448, 2.570, 2.695, 2.776, 3.097, 3.470])  # V
f_MHz = np.array([14.745] * 8)  # MHz，全部相同
Vpp = np.array([0.309, 0.335, 0.341, 0.361, 0.377, 0.383, 0.409, 0.419])  # V

# 创建双子图
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(9, 7), sharex=True)

# 上图：频率 vs VB
ax1.plot(VB, f_MHz, "bo-", linewidth=2, markersize=7, color="#1f77b4")
ax1.set_ylabel("振荡频率 f (MHz)", fontsize=12)
ax1.grid(True, linestyle="--", alpha=0.7)
ax1.set_title("石英晶体振荡器特性：静态工作点对频率与幅度的影响", fontsize=14, pad=12)
ax1.tick_params(axis="y", labelsize=11)

# 标注频率几乎不变
ax1.annotate(
    "频率高度稳定\n(≈14.745 MHz)",
    xy=(VB[-1], f_MHz[-1]),
    xytext=(+30, -20),
    textcoords="offset points",
    fontsize=11,
    bbox=dict(boxstyle="round,pad=0.4", facecolor="#e6f2ff"),
    arrowprops=dict(arrowstyle="->", color="blue"),
)

# 下图：VP-P vs VB
ax2.plot(VB, Vpp, "ro-", linewidth=2, markersize=7, color="#d62728")
ax2.set_xlabel("基极电压 $V_B$ (V)", fontsize=12)
ax2.set_ylabel("输出峰峰值 $V_{P-P}$ (V)", fontsize=12)
ax2.grid(True, linestyle="--", alpha=0.7)
ax2.tick_params(axis="x", labelsize=11)
ax2.tick_params(axis="y", labelsize=11)

# 添加趋势说明
ax2.annotate(
    "幅度随 $V_B$ 增大而增大",
    xy=(VB[-2], Vpp[-2]),
    xytext=(-80, +30),
    textcoords="offset points",
    fontsize=11,
    bbox=dict(boxstyle="round,pad=0.4", facecolor="#ffe6e6"),
    arrowprops=dict(arrowstyle="->", color="red"),
)

# 调整布局
plt.tight_layout()
plt.savefig("晶体振荡器_VB影响特性.png", dpi=300, bbox_inches="tight")
plt.show()
