#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(int n, int k, int st) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }
        // cout << path.size() << endl;
        for (int i = st; i <= n; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
};