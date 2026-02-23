#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int climbStairs(int n, vector<int>& costs) {
        // int n = costs.size();
        int f0 = 0, f1 = 0, f2 = 0;
        for (int i = 0; i < n; i++) {  // 这里需要记住，我们枚举当前有的阶梯数量
            int f_new = costs[i] + min(min(f0 + 9, f1 + 4), f2 + 1);
            f0 = f1;
            f1 = f2;
            f2 = f_new;
        }
        return f2;
    }
};