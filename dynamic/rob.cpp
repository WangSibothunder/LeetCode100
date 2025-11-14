#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int numsSize = nums.size();
        if (numsSize == 1)
            return nums[0];
        else if (numsSize == 2)
            return max(nums[0], nums[1]);
        int maxMoney[numsSize];
        maxMoney[0] = nums[0], maxMoney[1] = max(nums[0], nums[1]);
        for (int i = 2; i < numsSize; i++)
        {
            maxMoney[i] = max(maxMoney[i - 1], maxMoney[i - 2] + nums[i]);
        }
        return maxMoney[numsSize - 1];
    }
};