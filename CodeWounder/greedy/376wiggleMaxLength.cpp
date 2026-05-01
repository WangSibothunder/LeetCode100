#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1) return size;
        if (size == 2) {
            if (nums[0] == nums[1])
                return 1;
            else
                return 2;
        }
        int times = 0;
        int i;
        int dir;
        int curDir;
        for (i = 1; i < size; i++) {
            if (nums[i] == nums[i - 1]) continue;
            dir = (nums[i] - nums[i - 1]) > 0;  // bigger dir is 1
            times++;
            break;
        }
        i++;
        for (i; i < size; i++) {  // for the next element of entrance
            if (nums[i] == nums[i - 1]) continue;
            curDir = nums[i] - nums[i - 1] > 0;
            if (curDir != dir) {
                times++;
                dir = curDir;
            }
        }
        times++;
        return times;
    }
};