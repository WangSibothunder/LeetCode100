#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> f(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        // f[trade day][0:sell,1:hold][trade times] = max profit
        f[0][1] = vector<int>(k + 1, INT_MIN);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k && j <= i; j++) {
                // f[i][j]:在第i-1天交易过j-1次（从0记数）
                f[i + 1][0][j] = max(f[i][0][j], f[i][1][j - 1] + prices[i]);
                f[i + 1][1][j] = max(f[i][1][j], f[i][0][j - 1] - prices[i]);
            }
        }
        return f[n][0][k];
    }
};