#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n; i > 0; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j) dp[i][j] = 1;
                if (s[i - 1] == s[j - 1]) {
                    if (i == j - 1) dp[i][j] = dp[i][j - 1]
                }
            }
        }
    }
};