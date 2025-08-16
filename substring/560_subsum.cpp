#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int> nums = {1,1,1};
    int k = 2,ans = 0,temp = 0;
    unordered_map<int,int> sum_up;
    sum_up[0] = 1;
    for(int i = 0; i<nums.size();i++){
        temp+=nums[i];
        if(sum_up.count(temp-k)){
            ans+=sum_up[temp-k];
        }
        sum_up[temp]++;
    }
    printf("ans = %d\n",ans);
    return 0;
}