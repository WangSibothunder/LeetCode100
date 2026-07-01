#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    string decodeString(string s) {
        s = "1[" + s + "]";
        string ans = "", temp = "";
        string last = "";
        stack<string> strStack;
        stack<int> timeStack;
        // strStack.push("");
        bool num = 0;
        for (int i = 0; i < s.size(); i++) {
            // //cout << temp << endl;
            char ch = s[i];
            if (ch >= '0' && '9' >= ch) {
                if (!num) {
                    num = 1;
                    timeStack.push(int(ch - '0'));
                } else {
                    int time = timeStack.top() * 10 + int(ch - '0');
                    timeStack.pop();
                    timeStack.push(time);
                }
                // //cout << "**" << endl;
            } else if (ch == '[') {
                num = 0;
                strStack.push(temp);
                temp = "";
            } else if ('z' >= ch && ch >= 'a') {
                temp += ch;
            } else if (ch == ']') {
                string cur = "";

                for (int j = 0; j < timeStack.top(); j++) {
                    cur += temp;
                }
                timeStack.pop();
                // cout << "cur: " << cur << endl;
                string last = strStack.top();
                strStack.pop();
                last += cur;
                // cout << "last: " << last << endl;
                //  strStack.push(last);
                temp = last;
                // temp = "";
            }
        }
        // string ans = "";
        while (!strStack.empty()) {
            ans = strStack.top() + ans;
            strStack.pop();
        }
        return temp;
    }
};

int main() {
    string cur = "";
    char ch = 'a';
    cur += ch;
    // cout << cur << endl;
    return 0;
}