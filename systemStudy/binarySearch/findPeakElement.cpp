#include<iostream>
#include<vector>
using namespace std;
//二分查找，【mid】和左右【mid+1】【mid-1】比大小
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0,right = nums.size()-1;
        int mid;//[1，2，3，4]左侧取2
        if(right==0) return 0;
        else if(right==1) return nums[0]<nums[1];
        while (left<=right)
        {
            mid = (left+right)>>1;//[1，2，3，4]左侧取2
            if(mid==0||mid==nums.size()-1){
                printf("mid到两侧\n");
                printf("left = %d,right = %d,mid = %d\n",left,right,mid);
                break;
            } 
            
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]){
                printf("找到峰值\n");
                printf("left = %d,right = %d,mid = %d\n",left,right,mid);
                break;
            } else if(nums[mid]>nums[mid-1]&&nums[mid]<nums[mid+1]){
                left = mid+1;
                printf("全上升\n");
                printf("left = %d,right = %d,mid = %d\n",left,right,mid);
            } else if(nums[mid]<nums[mid-1]&&nums[mid]>nums[mid+1]){
                right = mid;
                printf("全下降\n");
                printf("left = %d,right = %d,mid = %d\n",left,right,mid);
            } else left = mid+1;
        }
        return nums[mid];
        
    }
};
int main(){
    Solution a;
    vector<int>nums = {9,7,3,7,8};
    int ans = a.findPeakElement(nums);
    printf("峰值为%d\n",ans);
    return 0;
}