#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int length = nums.size();
        int end = 0;
        int maxPosition = 0;
        int steps = 0;
        for (int i = 0; i < length - 1; i++)
        {
            maxPosition = max(maxPosition, i + nums[i]);
            if (i == end)
            {
                end = maxPosition;
                steps++;
            }
        }
        return steps;
    }
};
