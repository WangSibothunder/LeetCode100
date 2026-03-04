#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> moreThan;
        for (int i = 0; i < n; i++) {
            if (moreThan.find(nums[i]) != moreThan.end())
                moreThan[nums[i]]++;
            else
                moreThan[nums[i]] = 1;
        }

        int temp = -1, ans;
        for (auto pp : moreThan) {
            if (pp.second > temp) {
                temp = pp.second;
                ans = pp.first;
            }
        }
        return ans;
    }
};