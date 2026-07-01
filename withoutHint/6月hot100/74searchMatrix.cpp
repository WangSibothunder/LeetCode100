#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_left = 0;
        int row_right = matrix.size() - 1;
        while (row_left <= row_right) {
            int mid = (row_left + row_right) >> 1;
            if (matrix[mid][0] > target)
                row_right = mid - 1;
            else
                row_left = mid + 1;
        }
        if (row_left == 0) return false;
        int col_left = 0;
        int col_right = matrix[0].size() - 1;
        while (col_left <= col_right) {
            int mid = (col_left + col_right) >> 1;
            if (matrix[row_left - 1][mid] > target)
                col_right = mid - 1;
            else
                col_left = mid + 1;
        }
        if (col_left == 0) return false;
        return matrix[row_left - 1][col_left - 1] == target;
    }
};