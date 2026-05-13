#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int d[1001]{};
        for (auto& trip : trips) {
            d[trip[1]] += trip[0];
            d[trip[2]] -= trip[0];
        }
        int s = 0;
        for (int i = 0; i < 1001; i++) {
            s += d[i];
            if (s > capacity) return false;
        }
        return true;
    }
};