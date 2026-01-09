import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

# Set global style for publication-quality plots
plt.rcParams["figure.dpi"] = 150
plt.rcParams["savefig.dpi"] = 300
sns.set(style="whitegrid", palette="muted")
colors = sns.color_palette("muted")

# -----------------------------
# Figure 1: UL vs UI (Effect of LO Voltage)
# -----------------------------
UL_V = np.array(
    [
        0.5,
        0.6,
        0.7,
        0.8,
        0.9,
        1.0,
        1.2,
        1.4,
        1.6,
        1.8,
        2.0,
        2.2,
        2.4,
        2.6,
        2.8,
        3.0,
        3.2,
        3.4,
        3.6,
        3.8,
        4.0,
        1.1,
        1.3,
    ]
)
UI_mV = np.array(
    [
        40.4,
        51.99,
        66.5,
        82,
        94.85,
        102.52,
        109,
        113,
        114.5,
        115.5,
        116,
        117.0,
        117.2,
        116.5,
        115.9,
        116.4,
        117,
        116.4,
        116,
        115.19,
        115.32,
        107,
        112.5,
    ]
)

# Sort by UL for smooth curve
sort_idx = np.argsort(UL_V)
UL_sorted = UL_V[sort_idx]
UI_sorted = UI_mV[sort_idx]

plt.figure(figsize=(8, 5))
plt.plot(
    UL_sorted,
    UI_sorted,
    marker="o",
    markersize=5,
    linewidth=2,
    color=colors[0],
    label=r"$U_I$ (mV)",
)
plt.axvline(x=1.3, color="gray", linestyle="--", alpha=0.7, label="Shifting Point")
plt.title("IF Output Amplitude $U_I$ vs. LO Voltage $U_L$", fontsize=14, weight="bold")
plt.xlabel("LO Voltage $U_L$ (V, peak-to-peak)", fontsize=12)
plt.ylabel("IF Output Amplitude $U_I$ (mV, peak-to-peak)", fontsize=12)
plt.legend()
plt.tight_layout()
plt.savefig("fig1_UL_vs_UI.png", bbox_inches="tight")
plt.show()

# -----------------------------
# Figure 2: US vs UI (Effect of RF Input Signal)
# -----------------------------
US_mV = np.array([10, 20, 30, 40, 50, 60, 70, 80, 90, 100])
UI_from_US = np.array(
    [26.42, 47.05, 70.92, 93.32, 116.74, 140.08, 165.72, 179.3, 211.51, 235.13]
)

plt.figure(figsize=(8, 5))
plt.plot(
    US_mV,
    UI_from_US,
    marker="s",
    markersize=6,
    linewidth=2.2,
    color=colors[2],
    label=r"$U_I$ (mV)",
)

# Ideal linear reference (slope from US=50 mV point)
slope = UI_from_US[4] / US_mV[4]  # ≈ 2.335
ideal_line = slope * US_mV
plt.plot(
    US_mV, ideal_line, "--", color="gray", alpha=0.7, label="Ideal Linear Reference"
)

plt.title(
    "IF Output Amplitude $U_I$ vs. RF Input Amplitude $U_S$", fontsize=14, weight="bold"
)
plt.xlabel("RF Input Amplitude $U_S$ (mV, peak-to-peak)", fontsize=12)
plt.ylabel("IF Output Amplitude $U_I$ (mV, peak-to-peak)", fontsize=12)
plt.legend()
plt.tight_layout()
plt.savefig("fig2_US_vs_UI.png", bbox_inches="tight")
plt.show()
