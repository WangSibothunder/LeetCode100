#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f(nums.size(), 1);
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    f[i] = max(f[i], f[j] + 1);
                    ans = max(ans, f[i]);
                }
            }
        }
        return f[nums.size() - 1];
    }
};