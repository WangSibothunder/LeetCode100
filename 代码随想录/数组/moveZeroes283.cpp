#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int st = 0, nz = 0;
        for (nz = 0; nz < nums.size(); nz++) {
            if (nums[nz] != 0) {
                nums[st++] = nums[nz++];
            } else
                nz++;
        }
        while (st < nums.size()) {
            nums[st] = 0;
        }
    }
};