#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

   public:
    vector<vector<int>> left_prefix_sum(
        vector<vector<int>>& grid) {  // left_down prefix sum
        int row = 0, col = 0;
        vector<vector<int>> left_prefix(grid);
        for (row = 1; row < grid.size(); row++) {
            for (col = 0; col < grid[0].size() - 1; col++) {
                left_prefix[row][col] =
                    grid[row][col] + left_prefix[row - 1][col + 1];
            }
        }
        return left_prefix;
    }
    vector<vector<int>> right_prefix_sum(
        vector<vector<int>>& grid) {  // right_down prefix sum
        int row = 0, col = 0;
        vector<vector<int>> right_prefix(grid);
        for (row = 1; row < grid.size(); row++) {
            for (col = 1; col < grid[0].size(); col++)
                right_prefix[row][col] =
                    grid[row][col] + right_prefix[row - 1][col - 1];
        }
        return right_prefix;
    }
    int cubeSum(int offset, int i, int j, vector<vector<int>>& left_prefix,
                vector<vector<int>>& right_prefix) {
        int left_1 = left_prefix[i][j - offset] - left_prefix[i - offset][j];
        int left_2 = left_prefix[i + offset][j] - left_prefix[i][j + offset];
        int right_1 = right_prefix[i][j + offset] - right_prefix[i - offset][j];
        int right_2 = right_prefix[i + offset][j] - right_prefix[i][j - offset];
        return left_1 + left_2 + right_1 + right_2;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<vector<int>> left_prefix = left_prefix_sum(grid);
        vector<vector<int>> right_prefix = right_prefix_sum(grid);
        vector<int> ans(3);
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                // int temp = grid[row][col];
                int offset = 1;
                if (grid[row][col] > max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = grid[row][col];
                } else if (grid[row][col] > max2) {
                    max3 = max2;
                    max2 = grid[row][col];
                } else if (grid[row][col] > max3) {
                    max3 = grid[row][col];
                }
                while ((row - offset) >= 0 && (row + offset) < grid.size() &&
                       (col - offset) >= 0 && (col + offset) < grid[0].size()) {
                    int Sum =
                        cubeSum(offset, row, col, left_prefix, right_prefix);
                    Sum =
                        Sum - grid[row + offset][col] + grid[row - offset][col];
                    if (Sum > max1) {
                        max3 = max2;
                        max2 = max1;
                        max1 = Sum;
                    } else if (Sum > max2) {
                        max3 = max2;
                        max2 = Sum;
                    } else if (Sum > max3) {
                        max3 = Sum;
                    }
                    offset++;
                }
            }
        }
        ans[0] = max1;
        ans[1] = max2;
        ans[2] = max3;
        return ans;
    }
};
int main() {
    vector<vector<int>> grid = {{3, 4, 5, 1, 3},
                                {3, 3, 4, 2, 3},
                                {20, 30, 200, 40, 10},
                                {1, 5, 5, 4, 1},
                                {4, 3, 2, 2, 5}};
    Solution sol;
    sol.getBiggestThree(grid);
    return 0;
}