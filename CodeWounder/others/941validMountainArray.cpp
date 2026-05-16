#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool validMountainArray(vector<int>& arr) {
        int st = 1, flag = 0, stop = 0;
        if (arr.size() <= 2) return false;
        for (; st < arr.size(); st++) {
            if (flag == 0) {
                if (arr[st] > arr[st - 1])
                    continue;
                else if (arr[st] == arr[st - 1])
                    return false;
                else if (st == 1)
                    return false;
                flag = 1;
            }
            if (flag == 1) {
                if (arr[st] < arr[st - 1])
                    continue;
                else
                    return false;
            }
        }
        if (flag == 0) return false;
        return true;
    }
};