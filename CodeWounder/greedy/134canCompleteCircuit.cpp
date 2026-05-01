#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> rest(gas);
        int size = gas.size();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            rest[i] = gas[i] - cost[i];
            sum += rest[i];
        }
        if (sum < 0) return -1;
        sum = 0;
        for (int i = 0; i < size; i++) {
            int upper = i + size;
            while (i < upper) {
                sum += rest[i % size];
                i++;
                if (sum < 0) {
                    // sum = 0;
                    break;
                }
            }
            if (sum >= 0) return i - size;
            sum = 0;
        }
        return -1;
    }
};