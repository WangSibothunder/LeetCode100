#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        int mid;
        if(right<=1){
            for(int i = 0;i<=right;i++){
                if (nums[i]==target) return i;
            }
            return -1;
        }
        while (left<=right)
        {
            mid = (left+right)>>1;
            printf("left = %d,right = %d,mid = %d\n",left,right,mid);
            printf("nums[mid]=%d\n",nums[mid]);
            if(nums[mid]==target) return mid;
            if(nums[0]<nums[mid]){
                if(nums[mid]>target&&target>=nums[0]) right=mid-1;
                else left = mid+1;
            } else{
                if(nums[mid]<target&&target<=nums.back()) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};
int main(){
    vector<int> nums = {8,1,2,3,4,5,6,7};
    int target = 6;
    Solution a;
    int ans = a.search(nums,target);
    printf("索引=%d,值为=%d",ans,ans!=-1?nums[ans]:-1);
    return 0;
}