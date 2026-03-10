#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    string simplifyPath(string path) {
        path += '/';
        int len = path.size();
        string valid_len = "";
        stack<string> validstk;
        int i = 1;
        while (i < len) {
            int j = i;
            while (path[j] != '/') j++;
            string temp = path.substr(i, j - i);
            while (j < len && path[j] == '/') j++;
            i = j;
            if (temp == ".") continue;
            if (temp == "..") {
                if (validstk.empty())
                    continue;
                else
                    validstk.pop();
            } else
                validstk.push(temp);
        }
        while (!validstk.empty()) {
            valid_len += '/' + validstk.top();
            validstk.pop();
        }
        if (validstk.empty()) return "/";
        while (!validstk.empty()) {
            valid_len = '/' + validstk.top() + valid_len;
            validstk.pop();
        }
        return valid_len;
    }
};
int main() {
    string path = "/home/";
    Solution sol;
    string re = sol.simplifyPath("/home/");
    return 0;
}