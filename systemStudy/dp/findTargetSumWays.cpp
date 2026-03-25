#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = reduce(nums.begin(), nums.end()) - abs(target);
        if (s < 0 || s % 2) return 0;
        int m = s / 2;  // 我们需要在nums中取数，使其和=m
        int n = nums.size();
        vector f(n + 1,
                 vector<int>(m + 1, 0));  // f[当前枚举值的数量][和] = 方法数
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j < nums[i])
                    f[i + 1][j] = f[i][j];  // 不选第i个物品能达到j容量的方案
                else
                    f[i + 1][j] = f[i][j] + f[i][j - nums[i]];
            }
        }
        return f[n][m];
    }
};