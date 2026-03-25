#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        int i = 0, j = n - 1, cur = n - 1;  // 相向双指针
        double abs1 = nums[i] * nums[i];
        double abs2 = nums[j] * nums[j];
        while (i < j) {
            if (abs1 > abs2) {
                nums[cur--] = abs1;
                i++;
                abs1 = nums[i] * nums[i];
            } else {
                nums[cur--] = abs2;
                j--;
                abs2 = nums[j] * nums[j];
            }
        }
        return nums;
    }
};