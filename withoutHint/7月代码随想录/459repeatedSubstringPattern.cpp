#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> next;
    void init(string s) {
        int pos = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[pos]) {
                next[i] = pos++;
            } else {
                while (pos != 0 && s[i] != s[pos]) {
                    pos = next[pos - 1] + 1;
                }
                if (s[i] == s[pos]) {
                    next[i] = pos;
                    pos++;
                }
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        next = vector<int>(s.size(), -1);
        init(s);
        for (int i = 0; i < s.size(); i++) printf("%d ", next[i]);
        cout << endl;
        int re = s.size() - next[s.size() - 1] - 1;
        return !(s.size() % re);
    }
};