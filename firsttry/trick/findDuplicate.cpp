#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast =nums[nums[0]],slow = 0;
        while(fast!=slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        int finder = 0;
        while(slow!=finder){
            finder = nums[finder];
            slow = nums[slow];
        }
        return slow;
    }
};