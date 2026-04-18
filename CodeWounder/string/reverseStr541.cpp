#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i + 2 * k < s.size()) {
            reverse(s.begin() + i, s.begin() + i + k);
            i += 2 * k;
        }
        if (i < s.size()) reverse(s.begin() + i, s.end());
        return s;
    }
};