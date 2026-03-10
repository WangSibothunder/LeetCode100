#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string reverseWords(string s) {
        string f = "";
        int n = s.size();
        int st = n, ed = n;
        bool flag = 0;
        s = ' ' + s;
        for (int j = n; j >= 0; j--) {
            if (flag == 0 && s[j] != ' ') {
                flag = 1;
                ed = j;
            }
            if (flag) {
                if (s[j] != ' ')
                    st = j;
                else {
                    f = f + (s.substr(st, (ed - st + 1))) + " ";
                    flag = 0;
                }
            }
        }

        return f.substr(0, f.size() - 1);
    }
};

int main() {
    string test = "the sky is blue";
    Solution sol;
    string re = sol.reverseWords(test);
    return 0;
}