#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(int startIndex, vector<int>& nums) {
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); i++) {
            bool flag = 0;
            if (path.empty() && !uset.count(nums[i])) {
                path.push_back(nums[i]);
                uset.insert(nums[i]);
                flag = 1;
            } else if (!path.empty() && nums[i] < path[path.size() - 1] ||
                       uset.count(nums[i]))
                continue;
            if (flag == 0) {
                path.push_back(nums[i]);
                uset.insert(nums[i]);
            }
            if (path.size() > 1) ans.push_back(path);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }

   public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(0, nums);
        return ans;
    }
};