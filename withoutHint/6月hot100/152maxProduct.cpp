#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        vector<long long int> imax(nums.size()), imin(nums.size());
        imax[0] = nums[0];
        imin[0] = nums[0];
        long long int ans = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                imax[i] = max((long long int)nums[i], nums[i] * imax[i - 1]);
                imin[i] = min((long long int)nums[i], imin[i - 1] * nums[i]);
            } else {
                imax[i] = max((long long int)nums[i], nums[i] * imin[i - 1]);
                imin[i] = min((long long int)nums[i], nums[i] * imax[i - 1]);
            }
            ans = max(ans, imax[i]);
        }
        return ans;
    }
};