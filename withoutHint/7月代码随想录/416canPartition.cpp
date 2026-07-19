#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); i++) target += nums[i];
        if (target % 2) return false;
        target /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }

        return dp[nums.size()][target];
    }
};