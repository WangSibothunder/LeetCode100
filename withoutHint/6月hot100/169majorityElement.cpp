#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int times = 1;
        int candidate = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (candidate == nums[i])
                times++;
            else {
                if (times > 1)
                    times--;
                else {
                    candidate = nums[i];
                }
            }
        }
        return candidate;
    }
};