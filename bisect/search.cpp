#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;
        if(nums.size()==1) {
            if(nums[0]==target) return 0;
            else return -1;
        }
        int left = 0,right = nums.size()-1,dis = -1;
        int mid;
        while(left<=right){
            mid= (left+right)>>1;
            if(nums[mid]==target) return mid;
            if(nums[0]<=nums[mid]){
                if(nums[0] <= target && target < nums[mid]){
                    right = mid-1;
                } else left = mid+1;
            } else{
                if (nums[mid] < target && target <= nums[nums.size() - 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};