#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        vector<vector<pair<int, int>>> dp(
            days + 1,
            vector<pair<int, int>>(k + 2, {INT_MIN / 2, INT_MIN / 2}));
        for (int j = 0; j <= k + 1; j++) dp[0][j].first = 0;
        for (int i = 1; i <= days; i++) {
            for (int j = 1; j <= k + 1; j++) {
                dp[i][j].first =
                    max(dp[i - 1][j].first,
                        dp[i - 1][j].second + prices[i - 1]);  // 卖出
                dp[i][j].second =
                    max(dp[i - 1][j].second,
                        dp[i - 1][j - 1].first - prices[i - 1]);  // 买入
            }
        }
        return max(dp[days][k + 1].first, 0);
    }
};