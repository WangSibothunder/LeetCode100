#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtrack(vector<int>& nums, vector<int>& used, int n) {
        if (n == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = 1;
            path.push_back(nums[i]);
            backtrack(nums, used, n + 1);
            used[i] = 0;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size());
        backtrack(nums, used, 0);
        return ans;
    }
};