#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0,f1 = 0;
        bool flag = 0;
        for(int i = 1;i<n;i++){
            int f_new = max(f1,f0+nums[i]);
            f0 = f1;
            f1 = f_new;
        }
        int start_0 = f1;
        f0 = 0;
        f1 = 0;
        for(int i = 2;i<n;i++){
            int f_new = max(f1,f0+nums[i]);
            f0 = f1;
            f1 = f_new;
        }
        int start_1 = f1+nums[0];
        return max(start_0,start_1);
    }
};