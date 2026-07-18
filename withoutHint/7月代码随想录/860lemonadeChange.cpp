#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> bugets;
        for (int i = 0; i < bills.size(); i++) {
            bugets[bills[i]]++;
            int charge = bills[i] - 5;
            if (charge == 15) {
                if (bugets[10] > 0) {
                    bugets[10]--;
                    charge -= 10;
                }
            }
            if (charge == 10) {
                if (bugets[5] > 0) {
                    bugets[5]--;
                    charge -= 5;
                }
            }
            while (charge > 0) {
                if (bugets[5] > 0) {
                    bugets[5]--;
                    charge -= 5;
                } else
                    return false;
            }
        }
        return true;
    }
};