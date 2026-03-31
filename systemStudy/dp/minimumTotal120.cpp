#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n, INT_MAX);
        vector<int> temp(n, INT_MAX);
        f[0] = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    temp[j] = f[j] + triangle[i][j];
                } else if (j != i) {
                    temp[j] =
                        min(f[j] + triangle[i][j], f[j - 1] + triangle[i][j]);
                } else
                    temp[j] = f[j - 1] + triangle[i][j];
                if (i == n - 1) ans = min(ans, temp[j]);
            }
            f = temp;
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    // triangle = {{-11}};
    Solution sol;
    int re = sol.minimumTotal(triangle);
    cout << re << endl;
    return 0;
}