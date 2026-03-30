#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1, 1);
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j > 0; j--) {
                if (nums[j - 1] < nums[i - 1]) {
                    f[i] = max(f[j] + 1, f[i]);
                    ans = max(ans, f[i]);
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution sol;
    int re = sol.lengthOfLIS(nums);
    cout << re << endl;
    return 0;
}