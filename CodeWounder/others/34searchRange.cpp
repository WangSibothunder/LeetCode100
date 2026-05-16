#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (right >= left) {
            int mid = left + (right - left) >> 1;
            if (nums[mid] > nums[left])
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (left >= nums.size() || nums[left] != target) return {-1, -1};
        int st = left, ed = left;
        for (int i = st + 1; i < nums.size(); i++) {
            if (nums[i] == target) ed = i;
        }
        return {st, ed};
    }
};