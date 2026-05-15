#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(int targetSum, int n, int start) {
        if (n == 0) {
            if (targetSum == 0) ans.push_back(path);
            return;
        }
        for (int i = start; i <= 9 - n + 1; i++) {
            targetSum -= i;
            if (targetSum < 0) {
                targetSum += i;
                continue;
            }
            path.push_back(i);
            backtracking(targetSum, n - 1, i + 1);
            targetSum += i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 1);
        return ans;
    }
};