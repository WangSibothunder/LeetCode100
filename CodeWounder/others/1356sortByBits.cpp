#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    static bool cmp(int x, int y) {
        int bitX = 0;
        while (x != 0) {
            bitX += x & 1;
            x = x >> 1;
        }
        int bitY = 0;
        while (y != 0) {
            bitY += y & 1;
            y = y >> 1;
        }
        return bitX > bitY;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};