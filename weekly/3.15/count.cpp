#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    long long countCommas(long long n) {
        int exp = log10l(n);
        if (exp < 3)
            return 0;
        else {
            long long case1 = pow(10, 6) - pow(10, 3);
            long long case2 = case1 + 2 * (pow(10, 9) - pow(10, 6));
            long long case3 = case2 + 3 * (pow(10, 12) - pow(10, 9));
            long long case4 = case3 + 4 * (pow(10, 15) - pow(10, 12));
            if (exp < 6) {
                return n - pow(10, 3) + 1;
            } else if (exp < 9) {
                return case1 + 2 * (n - pow(10, 6) + 1);
            } else if (exp < 12) {
                return case2 + 3 * (n - pow(10, 9) + 1);
            } else if (exp < 15) {
                return case3 + 4 * (n - pow(10, 12) + 1);
            } else {
                return case4 + 5 * (n - pow(10, 15) + 1);
            }
        }
        return 0;
    }
};

int main() {
    long long n = 1122872257463;
    cout << log10l(n) << endl;
    return 0;
}