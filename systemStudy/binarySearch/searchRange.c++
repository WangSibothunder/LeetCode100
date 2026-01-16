#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        vector<int> ans = {-1, -1};
        if (right == -1 || (right == 0 && nums[0] != target))
            return ans;
        if (right == 0 && nums[0] == target)
        {
            ans[0] = 0;
            ans[1] = 0;
            return ans;
        }
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            printf("left = %d,right = %d,mid = %d\n", left, right, mid);
            printf("nums[mid]=%d\n", nums[mid]);
            if (nums[mid] >= target)
                right = mid - 1; // 1,2,2,3找2，left = 0=right
            else
                left = mid + 1;
        }
        if (nums[left] == target)
        {
            printf("找到目标值，left=%d\n", left);
            ans[0] = left;
            right = nums.size() - 1;
            while (left <= right)
            {
                int mid = (left + right) >> 1;
                if (nums[mid] > target)
                    right = mid - 1; // 1,2,2,3找2，left = 0=right
                else
                    left = mid + 1;
            }
            ans[1] = left - 1;
            printf("找到目标值，right=%d\n", left - 1);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 2};
    int target = 1;
    Solution a;
    vector<int> ans = a.searchRange(nums, target);
    printf("ans = [%d,%d]", ans[0], ans[1]);
    return 0;
}