#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0, n = stones.size();
        if (n == 1) return stones[0];
        for (auto& sto : stones) sum += sto;
        int half = sum / 2;
        // cout<<"sum:"<<sum<<endl;
        // cout<<"half:"<<half<<endl;
        vector<vector<int>> dp(n + 1, vector<int>(half + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
            // if (stones[i - 1] <= half) dp[i][stones[i - 1]] = 1;
        }
        int i = 1, max_index = 1;
        for (; i < n; i++) {
            for (int j = 1; j <= half; j++) {
                if (stones[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - stones[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        // cout<<"i:"<<i<<endl;
        for (int j = 1; j <= half; j++) {
            if (stones[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - stones[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
            if (dp[i][j] != 0) max_index = j;
            // cout << dp[i][j] << " ";
            // cout << endl;
        }
        return (sum - max_index) - max_index;
    }
};