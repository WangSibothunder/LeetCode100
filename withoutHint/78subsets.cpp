#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> path;
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int layer) {
        for (int i = layer; i < nums.size(); i++) {
            path.push_back(nums[i]);
            ans.push_back(path);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back(path);
        backtrack(nums, 0);
        return ans;
    }
};