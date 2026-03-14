#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int helper(int start, int end, int target, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for (int i = end - 1; i >= start; i++) {
            for (int j = i + 1; j <= end; j++) {
                if (nums[i] + nums[i + 1] == target) {  // 删除前两个数
                    f[i][j + 1] = max(f[i][j + 1], f[i + 2][j + 1] + 1);
                }
                if (nums[j - 1] + nums[j] == target) {  // 删除后两个数
                    f[i][j + 1] = max(f[i][j + 1], f[i][j - 1] + 1);
                }
                if (nums[i] + nums[j] == target) {  // 删除第一个和最后一个数
                    f[i][j + 1] = max(f[i][j + 1], f[i + 1][j] + 1);
                }
            }
        }
    }

   public:
    int maxOperations(vector<int>& nums) {}
};