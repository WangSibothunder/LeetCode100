#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] == i + 1) continue;
            while (nums[i] > 0 && nums[i] != i + 1) {
                swap(nums[i], nums[nums[i] + 1]);
            }
        }
    }
};