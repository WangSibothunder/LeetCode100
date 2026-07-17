#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(vector<int>& nums, int st) {
        ans.push_back(path);
        for (int idx = st; idx < nums.size(); idx++) {
            if (idx > st && nums[idx] == nums[idx - 1]) continue;
            path.push_back(nums[idx]);
            backtracking(nums, idx + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return ans;
    }
};