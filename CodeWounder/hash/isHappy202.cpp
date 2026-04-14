#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    unordered_set<int> uset;

   public:
    bool isHappy(int n) {
        while (n != 1) {
            if (uset.count(n)) return false;
            int temp = 0;
            while (n > 0) {
                temp += n % 10 * n % 10;
                n = n / 10;
            }
            uset.insert(temp);
            n = temp;
        }
        return true;
    }
};