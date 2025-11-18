#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<int> bisect(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, dis = -1;
        int right_bound = -1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (target <= nums[mid])
            {
                right = mid - 1;
                dis = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (dis != -1 && nums[dis] == target)
        {
            right_bound = dis;
            int i = dis + 1;
            for (i; i < nums.size(); i++)
            {
                if (nums[i] != target)
                {

                    break;
                }
            }
            right_bound = i - 1;
        }
        else
            dis = -1;
        vector<int> ans;
        // printf("left:%d,right:%d,mid:%d,dis:%d\n", left, right, mid, dis);
        ans.push_back(dis);
        ans.push_back(right_bound);
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> out = {-1, -1};
        if (nums.size() == 0 || (nums.size() == 1 && target != nums[0]))
            return out;
        else if ((nums.size() == 1 && target == nums[0]))
        {
            out = {0, 0};
            return out;
        }
        return bisect(nums, target);
    }
};

int main()
{
    vector<int> nums = {2, 2};
    Solution a;
    vector<int> out = a.searchRange(nums, 2);
    printf("%d,%d", out[0], out[1]);
    return 0;
}