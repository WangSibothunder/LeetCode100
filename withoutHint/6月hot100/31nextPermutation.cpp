#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int temp = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int j;
                for (j = nums.size() - 1; j > i; j--) {
                    if (nums[j] > nums[i]) break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};