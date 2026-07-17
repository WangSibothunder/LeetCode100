#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        if (nums.size() == 2) {
            if (nums[0] == nums[1]) return 1;
            return 2;
        }
        int times = 0, flag = -1, shift = 0;
        int slow = 0, fast = 1;
        if (nums[slow] < nums[fast])
            flag = 1;
        else if (nums[slow] > nums[fast])
            flag = 0;
        for (int i = fast + 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;
            if (shift == 0) shift = 1;
            if (nums[i] > nums[i - 1]) {
                if (flag == 0) times++;
                flag = 1;
            } else if (nums[i] < nums[i - 1]) {
                if (flag == 1) times++;
                flag = 0;
            }
        }
        if (shift == 0) return 1;
        return times + 2;
    }
};