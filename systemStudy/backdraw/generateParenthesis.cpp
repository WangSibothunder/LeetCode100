#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    string path = "";
    vector<string> ans;
    int n;
    int m;
    /*
    @param i 当前第几层
    @param open 有多少个左括号
    */
    void dfs(int i,int open){
        if(i==m) {
            ans.push_back(path);
            return;
        }
        if(open<n){
            path[i] = '(';
            dfs(i+1,open+1);
        }
        if(i-open<open){
            path[i] = ')';
            dfs(i+1,open);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        m = n*2;
        this->n = n;
        path = string(m, ' ');
        dfs(0,0);
        return this->ans;
    }
};