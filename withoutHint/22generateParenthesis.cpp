#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string path;
    vector<string> ans;
    void backtracking(int n, int left, int right) {
        if (n * 2 == left + right) {
            ans.push_back(path);
            return;
        }
        // for (int i = left + right; i < n; i++) {
        if (left == right) {
            path.push_back('(');
            backtracking(n, left + 1, right);
            path.pop_back();
        } else if (left == n) {
            path.push_back(')');
            backtracking(n, left, right + 1);
            path.pop_back();
        } else {
            path.push_back('(');
            backtracking(n, left + 1, right);
            path.pop_back();
            path.push_back(')');
            backtracking(n, left, right + 1);
            path.pop_back();
        }
        // }
    }
    vector<string> generateParenthesis(int n) {
        backtracking(n, 0, 0);
        return ans;
    }
};