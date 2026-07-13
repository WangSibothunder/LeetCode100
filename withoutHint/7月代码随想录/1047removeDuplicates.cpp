#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    string removeDuplicates(string s) {
        stack<char> ch;
        for (int i = 0; i < s.size(); i++) {
            if (ch.empty())
                ch.push(s[i]);
            else {
                if (s[i] == ch.top())
                    ch.pop();
                else
                    ch.push(s[i]);
            }
        }
        string ans = "";
        while (!ch.empty()) {
            ans = ch.top() + ans;
            ch.pop();
        }
        return ans;
    }
};