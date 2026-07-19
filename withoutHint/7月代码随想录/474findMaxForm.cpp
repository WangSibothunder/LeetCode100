#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {  // m个0，n个1
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto& ele : strs) {
            int one = 0, zero = 0;
            for (int i = 0; i < ele.size(); i++) {
                if (ele[i] == '0')
                    zero++;
                else
                    one++;
            }
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    // if (i >= zero && j >= one) {
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                    // }
                }
            }
        }
        return dp[m][n];
    }
};