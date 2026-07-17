#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> path, visited;
    vector<vector<int>> ans;

    void backtracking(vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        int last = -11;
        unordered_set<int> uset;
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || uset.count(nums[i])) continue;
            path.push_back(nums[i]);
            visited[i] = 1;
            uset.insert(nums[i]);
            backtracking(nums);
            path.pop_back();
            visited[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        visited = vector<int>(nums.size(), 0);
        backtracking(nums);
        return ans;
    }
};