#include <iostream>
#include <vector>
using namespace std;
// 二分查找列，二分查找行
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left_row = 0, right_row = matrix.size() - 1;
        while (left_row <= right_row)
        {
            int mid = (left_row + right_row) >> 1;

            if (target >= matrix[mid][0])
                left_row = mid + 1;
            else
                right_row = mid - 1;
        }
        int select_row = left_row - 1;
        if (select_row < 0)
            return false;
        int left_col = 0, right_col = matrix[0].size() - 1;
        while (left_col <= right_col)
        {
            int mid = (left_col + right_col) >> 1;
            // printf("mid = %d\n", mid);
            if (target >= matrix[select_row][mid])
                left_col = mid + 1;
            else
                right_col = mid - 1;
        }
        return target == matrix[select_row][left_col - 1];
        printf("坐标为：select_row:%d,select_col:%d\n", select_row, left_col - 1);
        return left_col - 1;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 9;
    Solution a;
    bool ans = a.searchMatrix(matrix, target);
    printf("ans = %d", ans);
    return 0;
}