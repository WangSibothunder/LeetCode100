#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int ans = 0;
    vector<vector<int>> grid;
    bool isValid(int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 1; i < n; i++) {
            int temp_x = x - i;
            if (temp_x >= 0) {
                if (grid[temp_x][y] == 1) return false;
                int temp_y = y - i;
                if (temp_y >= 0 && grid[temp_x][temp_y] == 1) return false;
                temp_y = y + i;
                if (temp_y < m && grid[temp_x][temp_y] == 1) return false;
            }
        }
        return true;
    }
    void backtracking(int layer, int n) {
        if (layer == n) {
            ans++;
        }
        vector<int> line(n);
        for (int i = 0; i < line.size(); i++) {
            line[i] = 1;
            grid.push_back(line);
            if (isValid(layer, i)) {
                backtracking(layer + 1, n);
            }
            grid.pop_back();
            line[i] = 0;
        }
    }
    int totalNQueens(int n) {
        backtracking(0, n);
        return ans;
    }
};