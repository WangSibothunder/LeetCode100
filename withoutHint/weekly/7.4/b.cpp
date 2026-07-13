#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxValidPairSum(vector<int>& nums, int k) {
        deque<int> pq;
        vector<int> localMax(nums.size());
        int ans = INT_MIN;
        int maxidx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[maxidx] < nums[i]) maxidx = i;
            localMax[i] = maxidx;
        }
        for (int i = nums.size() - 1; i > k; i--) {
            ans = max(ans, nums[localMax[i - k]] + nums[i]);
        }
        return ans;
    }
};
// ©leetcode