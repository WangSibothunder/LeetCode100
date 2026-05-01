#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int jump(vector<int>& nums) {
        int step = 0, curMaxDis = 0, nextMaxDis = 0;
        int size = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            nextMaxDis = max(nextMaxDis, 0) + i;
            if (i == curMaxDis) {
                step++;
                curMaxDis = nextMaxDis;
                if (nextMaxDis >= size) break;
            }
        }
        return step;
    }
};