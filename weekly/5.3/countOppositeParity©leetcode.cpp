#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> ans(nums);
        int even = 0, odd = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] % 2 == 1) {
                ans[i] = odd;
            } else {
                ans[i] = even;
            }
            even += (1 - nums[i] % 2);
            odd += nums[i] % 2;
        }
        return ans;
    }
};