#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<string> grid;
    vector<vector<string>> ans;
    bool isValid(vector<string>& grid, int x, int y) {
        int y1 = y, y2 = y;
        // int flag = 1;
        for (int i = x - 1; i >= 0; i--) {
            y1 = y1 - 1;
            y2 = y2 + 1;
            if (y1 >= 0)
                if (grid[i][y1] == 'Q') return false;
            if (y2 < grid[0].size())
                if (grid[i][y2] == 'Q') return false;
            if (grid[i][y] == 'Q') return false;
        }
        return true;
    }
    void backtracking(int x, int n) {
        if (x == n) {
            ans.push_back(grid);
            return;
        }
        for (int i = 0; i < n; i++) {
            // grid[x][y] = ;
            if (isValid(grid, x, i)) {
                grid[x][i] = 'Q';
                backtracking(x + 1, n);
                grid[x][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        grid = vector<string>(n, string(n, '.'));
        backtracking(0, n);
        return ans;
    }
};