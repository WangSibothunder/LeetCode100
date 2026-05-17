#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (int i = 0; i < moves.size(); i++) {
            char t = moves[i];
            if (t == 'U') y++;
            if (t == 'D') y--;
            if (t == 'L') x--;
            if (t == 'R') x++;
        }
        return x == 0 && y == 0;
    }
};