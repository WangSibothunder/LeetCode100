#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> robs(mx+1);
        // int n = nums.size();
        for(auto ch:nums){
            robs[ch]+=ch;
        }
        int f0 = 0,f1 = 0;
        for(auto rob:robs){
            int f_new = max(f1,f0+rob);
            f0 = f1;
            f1 = f_new;
        }
        return f1;
    }
};