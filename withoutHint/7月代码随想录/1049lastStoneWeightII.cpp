#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int target = 0;
        for (auto& st : stones) target += st;
        int temp = target;
        target /= 2;
        vector<vector<int>> dp(stones.size() + 1, vector<int>(target + 1));
        // dp[0][0] = 1;
        for (int i = 1; i <= stones.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= stones[i - 1])
                    dp[i][j] = max(dp[i - 1][j - stones[i - 1]] + stones[i - 1],
                                   dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        cout << temp << " " << dp[stones.size()][target];
        return abs(temp - dp[stones.size()][target] << 1);
    }
};