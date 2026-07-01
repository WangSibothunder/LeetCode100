#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int ptr = 1;
        int left = 0, right = nums.size();
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > 0)
                right = right - 1;
            else
                left = mid + 1;
        }
        int p = left, n = left - 1;
        ptr = 0;
        vector<int> ans(nums);
        while (p < nums.size() && n >= 0) {
            if ((0 - nums[n]) < nums[p]) {
                ans[ptr++] = pow(nums[n--], 2);
            } else
                ans[ptr++] = pow(nums[p++], 2);
        }
        while (p < nums.size()) ans[ptr++] = pow(nums[p++], 2);
        while (n >= 0) ans[ptr++] = pow(nums[n--], 2);
        return ans;
    }
};