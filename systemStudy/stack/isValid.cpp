#include <iostream>
#include <stack>
using namespace std;
class Solution {
   public:
    bool isValid(string s) {
        stack<char> validset;
        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{')
                validset.push(ch);
            else {
                if (validset.empty()) return false;
                if (validset.top() == '(' && ch != ')') return false;
                if (validset.top() == '[' && ch != ']') return false;
                if (validset.top() == '{' && ch != '}') return false;
                validset.pop();
            }
        }
        // if()
        return validset.empty() ? true : false;
    }
};