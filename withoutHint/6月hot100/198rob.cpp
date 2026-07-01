#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> f(nums.size() + 2);  // f[i]:到第i家可以抢到的最多的钱
        for (int i = 0; i < nums.size(); i++) {
            f[i + 2] = max(nums[i] + f[i], f[i + 1]);
        }
        return f[nums.size() + 1];
    }
};