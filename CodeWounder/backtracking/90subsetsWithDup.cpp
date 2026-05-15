#include <iostream>
#include <vector>
using namespace std;
class Solution {
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(int startIndex, vector<int>& nums) {
        // if(startIndex>=nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > startIndex && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            ans.push_back(path);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        backtracking(0, nums);
        return ans;
    }
};