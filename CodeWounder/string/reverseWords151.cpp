#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        s += ' ';
        int slow = 0, fast = 0, fast_st = 0;
        bool flag = 0;
        string temp;
        while (fast < s.size()) {
            if (s[fast] == ' ') {
                if (flag == 0) {
                    fast++;
                } else {
                    temp = s.substr(fast_st, fast - fast_st);
                    cout << temp << endl;
                    reverse(temp.begin(), temp.end());
                    for (int i = 0; i < fast - fast_st; i++) {
                        s[slow++] = temp[i];
                    }
                    s[slow++] = ' ';
                    flag = 0;
                    fast++;
                }
            } else {
                if (flag == 0) {
                    fast_st = fast;
                    flag = 1;
                    fast++;
                } else {
                    fast++;
                }
            }
        }
        s.resize(slow - 1);
        return s;
    }
};
int main() {
    string s = "a good   example";
    Solution sol;
    s = sol.reverseWords(s);
    cout << s << endl;
    return 0;
}