#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums.back();
        // 去掉数组中最小值开始到
        int start = 0, stop = 0;
        int min = INT_MAX;
        bool cnt_flag = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < min) {
                min = nums[i];
                start = i;
                cnt_flag == 1;
            }
            if (cnt_flag == 1 && nums[i]) }
    }
};