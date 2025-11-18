#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {1,2, 3, 4,5};
    //          left    1 1  2  6  24
    //          right   1 4  12 24 24
    //          ans.   24 12 8  6

    vector<int> ans(nums.size(), 0), mul_left = {1}, mul_right = {1};
    bool is_odd = nums.size()%2;
    for(int i = 0;i<nums.size();i++){
        mul_left.push_back(nums[i]*mul_left.back());
        mul_right.push_back(nums[nums.size()-i-1]*mul_right.back());
        if(!is_odd){
        if(i>=nums.size()/2){//交越
            ans[i] = mul_left[i]*mul_right[nums.size()-i-1];
            ans[nums.size()-i-1] = mul_left[nums.size()-i-1]*mul_right[i];
        }} else{
            if(i == nums.size()/2) ans[i] = mul_left[i]*mul_right[i];
            else if(i>nums.size()/2){
                ans[i] = mul_left[i]*mul_right[nums.size()-i-1];
                ans[nums.size()-i-1] = mul_left[nums.size()-i-1]*mul_right[i];
            }
        }
    }
    for(int j =0;j<ans.size();j++){
        printf("ans第%d位是%d\n",j,ans[j]);
    }
    return 0;
}