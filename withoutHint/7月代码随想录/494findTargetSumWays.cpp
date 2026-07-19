#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sumup = 0;
        for (auto& num : nums) {
            sumup += num;
        }
        target = (sumup - target);
        if (target % 2) return 0;
        target = target >> 1;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        int zero = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (nums[i - 1] == 0) zero++;
            dp[i][0] = int(pow(2, zero));
        }
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size()][target];
    }
};