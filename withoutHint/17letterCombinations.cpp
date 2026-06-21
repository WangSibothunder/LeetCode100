#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    unordered_map<char, string> phoneMap{
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string path;
    vector<string> ans;
    void backtracking(string digits, int layer) {
        if (layer == digits.size()) {
            ans.push_back(path);
            return;
        }
        string usableChar = phoneMap[digits[layer]];
        for (auto& ch : usableChar) {
            path.push_back(ch);
            backtracking(digits, layer + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        backtracking(digits, 0);
        return ans;
    }
};