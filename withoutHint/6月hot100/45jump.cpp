#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int times = 0;
        int longest = 0;
        int i = 0;
        while (i < nums.size()) {
            longest = i;
            int budget = nums[i];
            int next = 0;
            for (int j = 1; j <= budget; j++) {
                int idx = i + j;
                if (idx >= nums.size() - 1) {
                    times++;
                    return times;
                }
                if (longest < nums[i + j] + i + j) {
                    next = i + j;
                    longest = nums[i + j] + i + j;
                }
            }
            times++;
            i = next;
        }
        return times;
    }
};