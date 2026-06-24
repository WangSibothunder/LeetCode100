#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if (right == -1) return {-1, -1};
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (nums[left] != target) return {-1, -1};
        int st = left;
        right = right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return {st, left - 1};
    }
};