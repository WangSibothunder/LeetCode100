#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution sol;
    int re = sol.searchInsert(nums, target);
    return 0;
}