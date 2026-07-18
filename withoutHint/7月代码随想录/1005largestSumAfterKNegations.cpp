#include <vector>
using namespace std;
class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min_idx = 0, ans = 0;
        int times = k;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && times > 0) {
                nums[i] = -nums[i];
                times--;
            }
            if (nums[i] < nums[min_idx]) min_idx = i;
            ans += nums[i];
        }
        if (times % 2) {
            ans -= nums[min_idx] * 2;
        }
        return ans;
    }
};