#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector f(n+1,vector<int>(target+1,INT_MIN/2-1));
        //f[当前有的nums选项][目标和] = 满足【】【】的最大长度
        f[0][0] = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=target;j++){
                if(nums[i]>j) f[i+1][j] = f[i][j];//这个时候这个数字是不能选的
                else f[i+1][j] = max(f[i][j], f[i][j-nums[i]]+1);
            }
        }
        if (f[n][target]<INT_MIN/2) f[n][target] = -1;
        return f[n][target];
    }
};
//nums[] = {1,1,5,4,5}, target = 3