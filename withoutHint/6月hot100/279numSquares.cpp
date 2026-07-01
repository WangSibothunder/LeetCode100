#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            int root = sqrt(i) + 1;
            for (int j = root; j >= 1; j--) {
                int power = j * j;
                f[i] = min(f[i], f[i - power] + 1);
            }
        }
        return f[n];
    }
};