#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> f(
            n, vector<vector<int>>(n, vector<int>(k + 1)));
        for (int i = n - 1; i >= 0; i--) {
            f[i][i] = vector<int>(k + 1, 1);
            for (int j = i + 1; j < n; j++) {
                int d = (s[i] - s[j] + 26) % 26;
                d = min(26 - d, d);
                for (int k_ = 0; k_ <= k; k_++) {
                    int res = max(f[i + 1][j][k_], f[i][j - 1][k_]);
                    f[i][j][k_] = res;
                    if (d == 0)
                        f[i][j] = f[i + 1][j - 1];
                    else if (d + k_ <= k)
                        f[i][j][k_] = max(res, f[i + 1][j - 1][d + k_]);
                }
            }
        }
        return f[0][n - 1][k];
    }
};