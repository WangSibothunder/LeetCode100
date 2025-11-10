import math

n = 2
# 修复pow函数的使用，假设是计算2的n次方
DFT = pow(2, n)
FFT = n/2*math.log(n, 2)
print(f"n = {n}, DFT = {DFT}, FFT = {FFT}")
# 修复while循环语法，使用Python语法
while (DFT < FFT):
    n = n +1
    DFT = pow(2, n)  # 修复pow函数使用
    FFT = n/2*math.log(n, 2)
    print(f"n = {n}, DFT = {DFT}, FFT = {FFT}")