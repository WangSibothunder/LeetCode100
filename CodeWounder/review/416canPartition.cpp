#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (auto& num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) return false;
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1));
        for (int i = 1; i < n + 1; i++) {
            dp[i][0] = 1;  // null is reachable
            if (nums[i - 1] <= sum / 2)
                dp[i][nums[i - 1]] = 1;  // itself is reachable
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum / 2; j++) {
                if (nums[i - 1] > sum / 2) continue;
                if (nums[i - 1] <= j)
                    dp[i][j] =
                        dp[i][j] || dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n][sum / 2];
    }
};
int main() {
    vector<int> nums = {
        4,  4,  4,  4,  4,  4,  4,  4,  8,  8,  8,  8,  8,  8,  8,  8,  12, 12,
        12, 12, 12, 12, 12, 12, 16, 16, 16, 16, 16, 16, 16, 16, 20, 20, 20, 20,
        20, 20, 20, 20, 24, 24, 24, 24, 24, 24, 24, 24, 28, 28, 28, 28, 28, 28,
        28, 28, 32, 32, 32, 32, 32, 32, 32, 32, 36, 36, 36, 36, 36, 36, 36, 36,
        40, 40, 40, 40, 40, 40, 40, 40, 44, 44, 44, 44, 44, 44, 44, 44, 48, 48,
        48, 48, 48, 48, 48, 48, 52, 52, 52, 52, 52, 52, 52, 52, 56, 56, 56, 56,
        56, 56, 56, 56, 60, 60, 60, 60, 60, 60, 60, 60, 64, 64, 64, 64, 64, 64,
        64, 64, 68, 68, 68, 68, 68, 68, 68, 68, 72, 72, 72, 72, 72, 72, 72, 72,
        76, 76, 76, 76, 76, 76, 76, 76, 80, 80, 80, 80, 80, 80, 80, 80, 84, 84,
        84, 84, 84, 84, 84, 84, 88, 88, 88, 88, 88, 88, 88, 88, 92, 92, 92, 92,
        92, 92, 92, 92, 96, 96, 96, 96, 96, 96, 96, 96, 97, 99};
    Solution sol;
    bool re = sol.canPartition(nums);
    cout << "re=" << re << endl;
    return 0;
}