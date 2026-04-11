#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int row_size, col_size;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

   public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= row_size || j >= col_size ||
            grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '2';
        for (auto ele : dir) {
            dfs(grid, i + ele[0], j + ele[1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        row_size = grid.size();
        col_size = grid[0].size();
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};