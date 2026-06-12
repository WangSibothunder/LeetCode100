#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int digitFrequencyScore(int n) {
        vector<int> buf = vector<int>(10);
        while (n) {
            buf[n % 10]++;
            n /= 10;
        }
        long long ans = 0;
        for (int i = 1; i < 10; i++) {
            ans += buf[i] * i;
        }
        return ans;
    }
};