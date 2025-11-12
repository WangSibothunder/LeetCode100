#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int numsSize = nums.size();
        int mostFar = 0;
        for (int i = 0; i < numsSize; i++)
        {
            if (i <= mostFar)
            {
                mostFar = max(mostFar, i + nums[i]);
                if (mostFar >= numsSize - 1)
                    return true;
            }
        }
        return false;
    }
};