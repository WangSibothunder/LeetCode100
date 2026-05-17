#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n; i >= 1; i--) {
            dp[i][i] = 0;
            for (int j = i + 1; j <= n; j++) {
                if (i + 1 == j && s[i - 1] == s[j - 1])
                    dp[i][j] = 0;
                else if (s[i - 1] == s[j - 1] && dp[i + 1][j - 1] == 0)
                    dp[i][j] = 0;
                else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                    for (int k = i + 1; k < j; k++) {
                        if (dp[i][k] == 0) {
                            dp[i][j] = min(dp[i][j], dp[k + 1][j] + 1);
                        }
                    }
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[1][n];
    }
};