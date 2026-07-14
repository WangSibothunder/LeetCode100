#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string path;
    vector<string> result;
    bool isValid(string s, int st, int end) {  // 左闭右闭
        if (end - st + 1 > 3 || end < st)
            return false;
        else if (end - st + 1 > 1) {
            if (s[st] == '0' || stoi(s.substr(st, end - st + 1)) > 255)
                return false;
        }
        return true;
    }
    void backtracking(string s, int st, int nums) {
        if (nums == 3) {
            if (isValid(s, st, (s.size() - 1))) {
                result.push_back(path + s.substr(st, s.size() - st));
            }
            return;
        }
        for (int i = st; i < st + 3 && i < s.size(); i++) {
            if (isValid(s, st, i)) {
                path += s.substr(st, i - st + 1);
                path += '.';
                backtracking(s, i + 1, nums + 1);
                path = path.substr(0, path.size() - (i - st + 2));
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
};