#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        vector<int> left(n, 0), right(n, 0);
        left[0] = 1;
        for (int i = 1; i < n; i++) {
            if (i == 1 || nums[i] - nums[i - 1] != nums[i - 1] - nums[i - 2])
                left[i] = 2;
            else
                left[i] = left[i - 1] + 1;
        }

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (i == n - 2 ||
                nums[i + 1] - nums[i] != nums[i + 2] - nums[i + 1])
                right[i] = 2;
            else
                right[i] = right[i + 1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i]);
        }

        for (int i = 0; i < n; i++) {
            vector<long long> candidates;
            if (i > 0) candidates.push_back((long long)nums[i] - nums[i - 1]);
            if (i + 1 < n)
                candidates.push_back((long long)nums[i + 1] - nums[i]);
            if (i > 0 && i + 1 < n) {
                long long diffSum = (long long)nums[i + 1] - nums[i - 1];
                if ((diffSum & 1LL) == 0) candidates.push_back(diffSum / 2);
            }

            for (long long d : candidates) {
                int leftCount = 0;
                if (i > 0) {
                    if (i == 1)
                        leftCount = 1;
                    else if ((long long)nums[i - 1] - nums[i - 2] == d)
                        leftCount = left[i - 1];
                    else
                        leftCount = 1;
                }
                int rightCount = 0;
                if (i + 1 < n) {
                    if (i + 1 == n - 1)
                        rightCount = 1;
                    else if ((long long)nums[i + 2] - nums[i + 1] == d)
                        rightCount = right[i + 1];
                    else
                        rightCount = 1;
                }

                ans = max(ans, 1 + leftCount + rightCount);
            }
        }

        return ans;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> tests = {
        {1, 1, 2, 3},
        {9, 7, 5, 10, 1, 4},
        {1, 3, 5, 8, 9},
        {79734, 13414, 52866, 11223, 46264, 42963},
    };
    for (auto& nums : tests) {
        cout << "[";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << (i + 1 < nums.size() ? "," : "");
        }
        cout << "] -> " << sol.longestArithmetic(nums) << "\n";
    }
    return 0;
}