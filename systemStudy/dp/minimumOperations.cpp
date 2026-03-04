#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;
class Solution {
   public:
    int minimumOperations(vector<int>& nums) {
        // the longest rising ele nums
        int ans = 0;
        int n = nums.size();
        vector<int> f(n, -1);
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return n - ranges::max(f);
    }
};