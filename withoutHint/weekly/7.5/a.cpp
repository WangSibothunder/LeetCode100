#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int myRange(int num) {
        int max = num % 10, min = num % 10;
        num /= 10;
        while (num) {
            int temp = num % 10;
            if (temp > max) max = temp;
            if (temp < min) min = temp;
            num /= 10;
        }

        return max - min;
    }
    int maxDigitRange(vector<int>& nums) {
        unordered_map<int, vector<int>> ordMap;
        int maxIdx = -1;
        for (int i = 0; i < nums.size(); i++) {
            int deita = myRange(nums[i]);
            ordMap[deita].push_back(i);
            if (deita > maxIdx) maxIdx = deita;
        }
        int ans = 0;
        for (int i = 0; i < ordMap[maxIdx].size(); i++) {
            ans += nums[ordMap[maxIdx][i]];
        }
        return ans;
    }
};
// ©leetcode