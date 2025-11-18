#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    k = k%nums.size();
    vector<int> ans;
    for(int i = nums.size()-k; i<nums.size();i++){
        ans.push_back(nums[i]);
    } 
    ans.insert(ans.end(), nums.begin()+k, nums.end());
    return 0;
}