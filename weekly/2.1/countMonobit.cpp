#include <math.h>

#include <iostream>
using namespace std;
class Solution {
   public:
    int countMonobit(int n) {
        int ans = log2(n + 1) + 1;
        return ans;
    }
};