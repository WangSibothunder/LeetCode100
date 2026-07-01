#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<string> path;
    vector<vector<string>> ans;
    bool isPra(string s) {
        string temp = s;
        reverse(s.begin(), s.end());
        return temp == s;
    }
    void backtracking(string s, int startIdx) {
        if (startIdx >= s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = startIdx; i < s.size(); i++) {
            string cutted = s.substr(startIdx, i - startIdx + 1);
            if (isPra(cutted)) {
                path.push_back(cutted);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
};