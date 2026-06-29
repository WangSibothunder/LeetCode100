#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int st = 0, maxLenth = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (s[i] == s[j]) {
                    if (i + 1 == j)
                        dp[i][j] = 2;
                    else if (dp[i + 1][j - 1] != 0)
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                if (dp[i][j] > maxLenth) {
                    maxLenth = dp[i][j];
                    st = i;
                }
            }
        }
        return s.substr(st, maxLenth);
    }
};