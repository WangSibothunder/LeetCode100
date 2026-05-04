#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f1(n + 1), f2(n + 1);
        // f1:w/o nums[n-1]
        f1[1] = nums[0];
        for (int i = 2; i <= n - 1; i++) {
            f1[i] = max(f1[i - 1], f1[i - 2] + nums[i - 1]);
        }
        f2[2] = nums[1];
        for (int i = 3; i <= n; i++) {
            f2[i] = max(f2[i - 1], f2[i - 2] + nums[i - 1]);
        }
        return max(f1[n - 1], f2[n]);
    }
};