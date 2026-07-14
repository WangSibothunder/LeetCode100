#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int st) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(path);
            return;
        }
        cout << target << endl;
        for (int i = st; i < candidates.size() && candidates[i] <= target;
             i++) {
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};