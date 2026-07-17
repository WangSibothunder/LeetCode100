#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int times = 1, longest = nums[0];
        int idx = 0;
        while (longest < nums.size() - 1) {
            idx += 1;
            int nxt = longest;
            for (int i = idx; i <= longest; i++) {
                if ((i + nums[i]) > (idx + nums[idx])) {
                    idx = i;
                }
            }
            longest = idx + nums[idx];
            cout << idx << " " << longest << endl;
            times++;
            // if(longest>=nums.size()-1) break;
        }

        return times;
    }
};