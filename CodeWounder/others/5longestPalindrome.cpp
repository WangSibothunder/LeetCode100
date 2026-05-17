#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        int st = 0, len = 1;
        for (int i = n; i >= 1; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j <= n; j++) {
                if (s[i - 1] == s[j - 1] && dp[i + 1][j - 1] != 0)
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else if (s[i - 1] == s[j - 1] && i + 1 == j)
                    dp[i][j] = 2;
                if (dp[i][j] > len) {
                    len = dp[i][j];
                    st = i - 1;
                }
            }
        }
        // for (int i = 0; i < n + 1; i++) {
        //     for (int j = 0; j < n + 1; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return s.substr(st, len);
    }
};