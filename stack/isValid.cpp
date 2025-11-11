#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;


class Solution {
    unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2) return false;
        stack <char> stk;
        for(char ch:s){
            if(pairs.count(ch)){
                if(stk.empty()||stk.top()!=pairs[ch]) return false;
                stk.pop();
            }
            else stk.push(ch);
        }
        return stk.empty();
    }
};