#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = reduce(nums.begin(),nums.end());
        bool ans = false;
        if(target%2) return ans;
        target = target/2;
        int n=nums.size();
        vector f(n+1,vector<int>(target+1,INT_MIN/2));
        f[0][0] = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<=target;j++){
                if(nums[i]>j) f[i+1][j] =f[i][j];
                else f[i+1][j] = max(f[i][j],f[i][j-nums[i]]);
            }
        }
        if(f[n][target]==0) ans = 1;
        return ans;
    }
};