#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0, total = 0;
        int st = 0;
        for (int i = 0; i < gas.size(); i++) {
            if (curSum < 0) {
                curSum = 0;
                st = i;
            }
            total += (gas[i] - cost[i]);
            curSum += (gas[i] - cost[i]);
        }
        if (total < 0) return -1;
        return st;
    }
};