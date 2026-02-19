#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    vector<string> ans{};
    string path = "";
    int digits_size;
public:
    void dfs(int dfs_i,string digits){
        if(dfs_i==digits_size) {
            ans.push_back(path);
            return;
        }
        string select_phoneMap = phoneMap[digits[dfs_i]];
        for(auto c:select_phoneMap){
            path.push_back(c);
            dfs(dfs_i+1,digits);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        digits_size = digits.size();
        if(digits_size==0) return ans;
        dfs(0,digits);
        return ans;
    }
};