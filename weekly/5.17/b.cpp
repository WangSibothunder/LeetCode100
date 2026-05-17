#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int countKthRoots(int l, int r, int k) {
        int ans = 0;
        if (k != 1) {
            double st = floor(log(l) / log(k));
            if (l == 1) st = 1;
            double temp = pow(st, k);
            while (temp < l) {
                st += 1;
                temp = pow(st, k);
            }
            // cout << st << endl;
            double ed = ceil(log(r) / log(k));
            temp = pow(ed, k);
            while (temp > r) {
                ed -= 1;
                temp = pow(ed, k);
            }
            // cout << ed << endl;
            return ed - st + 1;
        }
        return r - l + 1;
    }
};
int main() {
    cout << log(30) / log(2) << endl;
    return 0;
}