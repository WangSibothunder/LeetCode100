#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(vector<int>& candidates, int target, int layer,
                      int psum) {
        if (psum > target) {
            return;
        } else if (psum == target) {
            ans.push_back(path);
            return;
        }
        for (int i = layer; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            psum += candidates[i];
            backtracking(candidates, target, i, psum);
            path.pop_back();
            psum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return ans;
    }
};