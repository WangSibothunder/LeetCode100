#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int numDistinct(string s, string t) {
        int s_size = s.size(), t_size = t.size();
        vector<vector<int>> dp(t_size + 1, vector<int>(s_size + 1));
        dp[0][0] = 1;  // empty = empty is one solution
        for (int i = 1; i <= t_size; i++) {
            for (int j = 1; j <= s_size; j++) {
                dp[i][j] = dp[i][j - 1];
                if (t[i - 1] == s[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[t_size][s_size];
    }
};