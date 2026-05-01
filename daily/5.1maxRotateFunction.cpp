#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxRotateFunction(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0;
        vector<double> lut(size);
        double sum = 0;
        for (int i = 0; i < size; i++) {
            lut[i] = nums[i] * size;
            sum += nums[i];
        }
        double sumMax = sum;
        int k = size;
        for (int i = size - 1; i >= 0; i--) {
            sum += sum - lut[i];
            if (sumMax < sum) {
                k = (size - 1) - i;
                sumMax = sum;
            }
        }
        return k;
    }
};