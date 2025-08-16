#include <iostream>
#include <vector>
using namespace std;

bool searchMatrixRec(vector<vector<int>> &matrix, int target,
                     int row_start, int row_end, int col_start, int col_end) {
    if (row_start > row_end || col_start > col_end) return false;

    // 找当前子矩阵的中点
    int row_mid = (row_start + row_end) / 2;
    int col_mid = (col_start + col_end) / 2;
    int mid_val = matrix[row_mid][col_mid];

    if (mid_val == target) return true;

    if (mid_val > target) {
        // target 比中点小 -> 去掉右下象限
        return searchMatrixRec(matrix, target, row_start, row_mid - 1, col_start, col_end) || // 上半部分
               searchMatrixRec(matrix, target, row_mid, row_end, col_start, col_mid - 1);    // 左半部分
    } else {
        // target 比中点大 -> 去掉左上象限
        return searchMatrixRec(matrix, target, row_mid + 1, row_end, col_start, col_end) || // 下半部分
               searchMatrixRec(matrix, target, row_start, row_mid, col_mid + 1, col_end);   // 右半部分
    }
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    return searchMatrixRec(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
}

int main() {
    vector<vector<int>> matrix = {
        {1,  4,  7, 11, 15},
        {2,  5,  8, 12, 19},
        {3,  6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 8;
    bool found = searchMatrix(matrix, target);
    cout << (found ? "Found" : "Not Found") << endl;
    return 0;
}
