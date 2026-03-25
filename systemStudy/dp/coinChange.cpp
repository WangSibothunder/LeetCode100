#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector f(n + 1,
                 vector<int>(
                     amount + 1,
                     INT_MAX - 1));  // f[看到第i枚硬币][前i枚硬币可以获得的和]
                                     // = 当前组合需要的最少硬币数量
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i] > j)
                    f[i + 1][j] = f[i][j];
                else
                    f[i + 1][j] = min(f[i][j], f[i + 1][j - coins[i]] + 1);
            }
        }
        int ans = f[n][amount];
        return ans < INT_MAX - 1 ? ans : -1;
    }
};