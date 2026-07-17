#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            temp += nums[i];
            if (temp < 0) {
                temp = 0;
                ans = max(ans, nums[i]);
            } else
                ans = max(ans, temp);
        }
        return ans;
    }
};