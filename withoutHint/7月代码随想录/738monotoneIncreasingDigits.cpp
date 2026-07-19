#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int monotoneIncreasingDigits(int n) {
        string ans = "";
        while (n) {
            int y = n % 10;
            int x = n / 10;
            n /= 10;
            if (x > y) {
                ans = '9' + ans;
                n -= 1;
            }
        }
    }
};