#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int k, int n, int st, int layer) {
        if (layer == k) {
            if (n == 0) result.push_back(path);
            return;
        }
        for (int i = st; i <= 9 && i <= n; i++) {
            path.push_back(i);
            backtracking(k, n - i, i + 1, layer + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return result;
    }
};