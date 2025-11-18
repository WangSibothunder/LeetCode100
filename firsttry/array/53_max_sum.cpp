#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums = {5,4,-1,7,8};
    int global_max=nums[0],local_max=nums[0];
    for(int i = 1; i<nums.size(); i++){
        //动态规划，从左侧开始的最大值规划，当前最值=max（之前的最值+当前值，当前值）
        local_max = max(local_max+nums[i],nums[i]);
        global_max = max(global_max,local_max);
    }
    printf("最大和：%d",global_max);
    return 0;
}