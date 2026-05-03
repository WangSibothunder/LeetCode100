#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto& ele : nums) {
            sum += ele;
        }
        if (sum % 2) return false;
        vector<vector<int>> f(n + 1, vector<int>(sum / 2 + 1));
        for (int i = 1; i <= n; i++) {  // i for weight
            f[i][nums[i - 1]] = 1;
            for (int j = 1; j <= sum / 2; j++) {  // j for value
                f[i][j] = f[i][j] || f[i - 1][j];
                if (j - nums[i - 1] >= 0)
                    f[i][j] = f[i][j] || (f[i - 1][j - nums[i - 1]]);
            }
        }
        return f[n][sum / 2];
    }
};
int main() {
    vector<int> nums = {1, 2, 5};
    Solution sol;
    bool re = sol.canPartition(nums);
    cout << re << endl;
    return 0;
}
