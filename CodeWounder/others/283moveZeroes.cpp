#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            nums[slowIndex] = nums[i];
            slowIndex++;
        }
        for (slowIndex; slowIndex < nums.size(); slowIndex++)
            nums[slowIndex] = 0;
        return;
    }
};