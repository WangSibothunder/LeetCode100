#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = 1, cur = 1;  // we suppose nums[0] was always ready
        while (i < n) {
            if (nums[i] == nums[i - 1]) {
                j = i;
                while (j < n && nums[j] == nums[i - 1]) {
                    j++;
                }
                i = j;
            }
            if (i != n) nums[cur++] = nums[i++];
        }
        return cur;
    }
};