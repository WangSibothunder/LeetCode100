#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1, cur = 1;  // we suppose nums[0] was always ready
        while (i < n) {
            if (nums[i] == nums[i - 1]) {
                int j = 0;
                while (i + j < n && nums[i + j] == nums[i - 1]) {
                    j++;
                }
                if (j > 1) i += j;
            }
            if (i != n) nums[cur++] = nums[i++];
        }
        return cur;
    }
};