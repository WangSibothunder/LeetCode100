#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 2, INT_MAX / 2));
        s = ' ' + s + ' ';
        f[0][n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= i; j--) {
                if (s[i - 1] == s[j + 1])
                    f[i][j] = f[i - 1][j + 1];
                else
                    f[i][j] = min(f[i - 1][j], f[i][j + 1]) + 1;
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) ans = min(ans, f[i][i + 1]);
        return ans;
    }
};
int main() {
    string s = "zjveiiwvc";
    Solution sol;
    int re = sol.minInsertions(s);
    cout << re << endl;
    return 0;
}