#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        vector<vector<int>> dp(day + 1, {0, 0});
        dp[0][1] = INT_MIN;
        for (int i = 1; i <= day; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i][0] - prices[i - 1]);
        }
        return max(0, dp[day][0]);
    }
};