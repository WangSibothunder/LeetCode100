#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, ans = INT_MAX;
        int i = 0;  // i为子数组的左端点
        for (int j = 0; j < n; j++) {
            // j为子数组的右端点
            sum += nums[j];
            while (i <= j && sum - nums[i] >= target) {
                sum -= nums[i];
                i++;
            }
            if (sum >= target) ans = min(ans, j - i + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
int main() {
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    Solution sol;
    bool re = sol.minSubArrayLen(target, nums);
    cout << re << endl;
    return 0;
}