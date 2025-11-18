#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
int main(){
    vector<int> nums = {3,4,-1,1};
    unordered_map<int,int> hashmap;
    for (int i=0;i<nums.size();i++){
        if(nums[i]>0) hashmap.emplace(nums[i],1);
    }
    int j;
    for(j = 1;j<1e5;j++){
        if(hashmap[j]!=1) break;
    }
    printf("%d\n",j);
    return 0;
}