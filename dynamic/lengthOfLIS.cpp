#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 0)
            return 0;
        vector<int> dp(size, 1);
        int ans = 1;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};