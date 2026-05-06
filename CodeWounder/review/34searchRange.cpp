#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ans(2);
        while (left <= right) {
            int middle = (left + right) >> 1;
            if (nums[middle] >= target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        if (left >= n || nums[left] != target) {
            ans[0] = -1, ans[1] = -1;
            return ans;
        }
        ans[0] = left;
        int i;
        for (i = left + 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                break;
            }
        }
        ans[1] = i - 1;
        return ans;
    }
};