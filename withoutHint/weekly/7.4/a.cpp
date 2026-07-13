#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int len = nums.size();
        int target = nums[len >> 1], times = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) times++;
        }
        return times == 0 ? 1 : 0;
    }
};