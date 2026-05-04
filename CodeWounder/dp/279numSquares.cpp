#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int numSquares(int n) {
        int upper = sqrt(n);
        vector<vector<int>> dp(upper + 1, vector<int>(n + 1, INT_MAX / 2));
        for (int i = 0; i <= upper; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= upper; i++) {
            for (int j = 1; j <= n; j++) {
                if (i * i > j)
                    dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - i * i] + 1);
                }
            }
        }
        if (dp[upper][n] >= INT_MAX / 2) return -1;
        return dp[upper][n];
    }
};