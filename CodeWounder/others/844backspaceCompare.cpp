#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        string newS, newT;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (newS.size() == 0) continue;
                newS.pop_back();
            } else
                newS += s[i];
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#') {
                if (newT.size() == 0) continue;
                newT.pop_back();
            } else
                newT += t[i];
        }
        return newS == newT;
    }
};