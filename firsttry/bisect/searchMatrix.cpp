#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int bisert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, dis = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                dis = mid;
                left = mid + 1;
            }
        }
        return dis;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        vector<int> matrix_row_first;
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix_row_first.push_back(matrix[i][0]);
        }
        int i = bisert(matrix_row_first, target);
        int j = bisert(matrix[i], target);
        if (matrix[i][j] == target)
            return true;
        else
            return false;
    }
};
int main()
{
    Solution a;
    vector<int> nums = {0, 3, 4, 8};
    //  0,1,2,3
    int out = a.bisert(nums, 5);
    printf("%d", out);
    return 0;
}