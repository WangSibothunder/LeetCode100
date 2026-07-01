#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int ptr = 0, p0 = 0, p1 = 0;
        for (ptr; ptr < nums.size(); ptr++) {
            if (nums[ptr] == 0) {
                if (p0 == p1) {
                    swap(nums[p0], nums[ptr]);
                    p0++;
                    p1++;
                } else {
                    swap(nums[p0], nums[ptr]);
                    swap(nums[p1], nums[ptr]);
                    p0++;
                    p1++;
                }
            } else if (nums[ptr] == 1) {
                swap(nums[p1], nums[ptr]);
                p1++;
            }
        }
    }
};