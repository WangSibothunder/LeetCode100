#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int rob(vector<int>& nums) {
        int f0 = 0, f1 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int f_new = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = f_new;
        }
        return f1;
    }
};