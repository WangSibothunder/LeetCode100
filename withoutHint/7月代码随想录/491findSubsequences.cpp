#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(vector<int>& nums, int st) {
        if (path.size() >= 2) ans.push_back(path);
        unordered_set<int> uset;
        for (int i = st; i < nums.size(); i++) {
            if (!uset.count(nums[i]) &&
                (path.empty() || nums[i] >= path.back())) {
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return ans;
    }
};

/*
 */