#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        // int time = 10;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            // if (time > 0) {
            //     cout << left << endl;
            //     time--;
            // }
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
int main() {
    vector<int> nums = {1, 3, 5, 6};
    Solution sol;
    int re = sol.searchInsert(nums, 5);
    cout << re << endl;
    return 0;
}