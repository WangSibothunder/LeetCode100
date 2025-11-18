#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size(), ans = 0;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] >= nums[0] && nums[mid] > nums[nums.size() - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};
int main()
{
    vector<int> nums = {2, 1};
    Solution a;
    int out = a.findMin(nums);
    printf("%d", out);
    return 0;
}