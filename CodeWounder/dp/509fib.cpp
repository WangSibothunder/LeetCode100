#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int fib(int n) {
        int f0 = 0, f1 = 1;
        if (n == 0) return f0;
        if (n == 1) return f1;
        int f3 = 0;
        for (int i = 0; i < n - 1; i++) {
            f3 = f0 + f1;
            f0 = f1;
            f1 = f3;
        }
        return f3;
    }
};