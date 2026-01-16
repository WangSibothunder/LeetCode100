#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int bisearch(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        if (right == 0)
            return left;
        if (right == 1)
        {
            return nums[left] >= nums[right];
        }
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            printf("left = %d,right = %d,mid = %d\n", left, right, mid);
            if (nums[mid] >= nums[0])
            {
                if (nums[mid] > nums.back())
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if (nums[mid] < nums.back())
                {
                    if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
                        right = mid - 1;
                    else
                        return mid;
                }
                else
                    return mid;
            }
        }
        return left;
    }
    int findMin(vector<int> &nums)
    {
        int ans = bisearch(nums);
        return nums[ans];
    }
};
int main()
{
    Solution a;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 0};
    int ans = a.bisearch(nums);
    printf("最小值下标为%d，值为%d\n", ans, a.findMin(nums));
    return 0;
}