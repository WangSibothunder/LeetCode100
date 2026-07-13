#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(2, vector<int>(m + 1, INT_MAX));
        dp[0] = vector<int>(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m && j < i; j++) dp[i % 2][j] = INT_MAX;
            for (int j = i; j <= m; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
                else {
                    dp[i % 2][j] =
                        min(dp[(i + 1) % 2][j - 1] + 1, dp[i % 2][j - 1]);
                }
            }
            if (dp[n % 2][m] > 1) return false;
            // for (int j = 1; j <= m; j++) cout << dp[i % 2][j] << " ";
            // cout << endl;
        }
        return dp[n % 2][m] == 1 || dp[n % 2][m] == 0;
    }
};
// ©leetcode