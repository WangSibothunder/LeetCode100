#include "TreeNode.h"

class Solution{
    /*
        Args:
            数组指针入口：&nums；左节点下标：left；右节点下标right；    
        */
    TreeNode* DSP(vector<int>& nums,int left,int right){
        if(left>right){//此时触发返回
            return nullptr;
        }
        int mid = (left+right)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = DSP(nums,left,mid-1);
        node->right = DSP(nums,mid+1,right);
        return node;}

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans;
        if(nums.size()==0) return ans;
        ans = DSP(nums,0,nums.size()-1);
        return ans;
    } 
};