#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = n - 2; i >= 0; i--) {
            f[i] = f[i + 1];
            for (int j = i + 1; j < n; j++) {
                if (s[i] == '(' && s[j] == ')') {
                    if (i + 1 == j)
                        f[i][j] = 1;
                    else if (i + f[i + 1][j - 1] * 2 + 1 == j)
                        f[i][j] = f[i + 1][j - 1] + 1;
                } else
                    f[i][j] = max(f[i][j - 1], f[i][j]);
            }
        }
        for (int j = 0; j < n; j++) {
            ans += f[0][j];
            printf("%d ", f[0][j]);
        }
        return ans;
    }
};