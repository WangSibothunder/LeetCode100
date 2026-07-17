#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int longest = nums[0];
        int idx = 0;
        while (idx <= longest && idx < nums.size()) {
            longest = max(longest, idx + nums[idx]);
            idx++;
        }
        return idx == nums.size();
    }
};