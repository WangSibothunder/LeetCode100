#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        int pre = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int cur = s[i] - '0';
            if (abs(cur - pre) > 2) return false;
            pre = cur;
        }
        return true;
    }
};