#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            cout << mid << endl;
            if (nums[mid] > nums.back()) {  // 中点落在第A段
                if (target > nums.back()) {
                    if (target < nums[mid])
                        right = mid - 1;
                    else
                        left = mid + 1;
                } else {
                    left = mid + 1;
                }
            } else {  // 中点落在第B段
                if (target > nums.back()) {
                    right = mid - 1;
                } else {
                    if (target < nums[mid]) {
                        right = mid - 1;
                    } else
                        left = mid + 1;
                }
            }
        }
        if (left == 0 || nums[left - 1] != target) return -1;
        return left - 1;
    }
};