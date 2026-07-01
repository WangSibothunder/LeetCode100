#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slow = 0, fast = 0, psum = 0, minLen = INT_MAX;
        while (fast < nums.size()) {
            while (psum < target && fast < nums.size()) {
                psum += nums[fast++];
            }
            while (psum >= target) {
                minLen = min(minLen, fast - slow);
                psum -= nums[slow++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};