#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, INT_MAX);
        f[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = f[i - 1]; i - j >= 0; j++) {
                f[i] = min(f[i], f[i - j] + 1);
            }
        }
        return f[n - 1];
    }
};