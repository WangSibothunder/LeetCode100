#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxFixedPoints(vector<int>& nums) {
        int temp = 0, ans = 0;
        vector<int> lut(nums);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i) temp++;
        }
        lut[nums.size() - 1] = temp;
        if (nums[nums.size() - 1] == nums.size() - 1) {
            lut[nums.size() - 1] -= 1;
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            lut[i] = lut[i + 1];
            if (nums[i] == i) {
                lut[i] -= 1;
            }
            if (nums[i + 1] == i) {
                lut[i] += 1;
            }
        }
    }
};