#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0, odd = 1;
        while (even <= nums.size() - 2 && odd <= nums.size() - 1) {
            while (even < nums.size() && nums[even] % 2 == 0) {
                even += 2;
            }
            while (odd < nums.size() && nums[odd] % 2 == 1) {
                odd += 2;
            }
            if (even < nums.size() && odd < nums.size())
                swap(nums[even], nums[odd]);
        }
        return nums;
    }
};