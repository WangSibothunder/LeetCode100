#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        stack<char> stack1, stack2;
        for (char ch : s) {
            if (ch == '#') {
                if (!stack1.empty()) stack1.pop();
            } else
                stack1.push(ch);
        }
        for (char ch : t) {
            if (ch == '#') {
                if (!stack2.empty()) stack2.pop();
            } else
                stack2.push(ch);
        }
        return stack1 == stack2;
    }
};