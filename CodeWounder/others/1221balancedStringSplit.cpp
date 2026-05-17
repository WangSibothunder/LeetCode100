#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int balancedStringSplit(string s) {
        int numL = 0, numR = 0, ans = 0;
        for (auto& ch : s) {
            if (ch == 'R')
                numR++;
            else
                numL++;
            if (numL > 0 && numR > 0 && numL == numR) {
                ans++;
                numL = 0;
                numR = 0;
            }
        }
        return ans;
    }
};