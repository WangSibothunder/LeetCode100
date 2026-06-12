#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        for (int x = max(1, n - k); x <= n + k; x++) {
            if ((n & x) == 0) ans += x;
        }
        return ans;
    }
};
int main() {
    int a = 31;
    int out = log2(a) + 1;
    cout << out;
    return 0;
}