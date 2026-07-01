#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            target += nums[i];
        }
        if (target % 2) return false;
        target = target >> 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> f(nums.size(), vector<int>(target + 1, 0));
        for (int i = 0; i < nums.size(); i++) {
            f[i][0] = 1;
            if (i > 0) f[i] = f[i - 1];
            for (int j = target; j >= nums[i]; j--) {
                f[i][j] = f[i][j - nums[i]] || f[i][j];
                if (f[i][target] == 1) return true;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                printf("%d ", f[i][j]);
            }
            printf("\n");
        }
        return false;
    }
};