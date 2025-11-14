#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    int maxmum = 0;
    int sum(vector<int> &nums)
    {
        int s = 0;
        for (auto &num : nums)
        {
            s += num;
            maxmum = max(maxmum, num);
        }

        return s;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int target = sum(nums) / 2;
        if (n == 0 || sum(nums) & 1 == 1 || maxmum > target)
            return false;
        vector<vector<int>> dp(n, vector<int>(target + 1));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = 1; j <= target; j++)
            {
                if (j >= num)
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n - 1][target];
    }
};