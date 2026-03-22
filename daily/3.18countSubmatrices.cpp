#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // my first thought is enumerate the first element
        // then i think that i can fisrt record the sum of element of the (0,0)
        // to (i,j)
        int row_len = grid.size();
        int col_len = grid[0].size();
        int ans = 0;
        // int temp = 0;
        vector<vector<int>> prefix_sum(row_len + 1,
                                       vector<int>(col_len + 1, 0));
        for (int i = 1; i <= row_len; i++) {  // cal the prefix
            for (int j = 1; j <= col_len; j++) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] + prefix_sum[i - 1][j] +
                                   grid[i - 1][j - 1] -
                                   prefix_sum[i - 1][j - 1];
            }
        }
        // enumrate the starting index;
        for (int i = 1; i <= row_len; i++) {  // cal the prefix
            for (int j = 1; j <= col_len; j++) {
                for (int end_row = i; end_row <= row_len; end_row++) {
                    for (int end_col = j; end_col <= col_len; end_col++) {
                        int submatrix = prefix_sum[end_row][end_col] -
                                        prefix_sum[end_row][j - 1] -
                                        prefix_sum[i - 1][end_col] +
                                        prefix_sum[i - 1][j - 1];
                        if (submatrix <= k) ans++;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid(4, vector<int>(4, 0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = i * 4 + j;
        }
    }
    Solution sol;
    int re = sol.countSubmatrices(grid, 12);
    return 0;
}