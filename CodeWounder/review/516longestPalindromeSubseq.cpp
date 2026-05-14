#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else {
                    if (s[i - 1] == s[j - 1])
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    else
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[1][n];
    }
};