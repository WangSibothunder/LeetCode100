#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int longest = 0, st = 0;
        int i = 0;
        while (i < nums.size()) {
            int budget = nums[i];
            if ((i + budget) >= nums.size() - 1) return true;
            longest = 0;
            st = i;
            for (int j = 1; j <= budget; j++) {
                if ((nums[i + j] + j) > longest) {
                    longest = nums[i + j] + j;
                    st = i + j;
                }
            }
            if (st == i) return false;
            i = st;
        }
        return true;
    }
};