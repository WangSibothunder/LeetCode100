#include "tree.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode* dfs(vector<int>& nums, int i, int j) {
        if (i > j) return nullptr;
        TreeNode* root = new TreeNode(nums[(i + j) >> 1]);
        root->left = dfs(nums, i, ((i + j) >> 1) - 1);
        root->right = dfs(nums, ((i + j) >> 1) + 1, j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        return dfs(nums, i, j);
    }
};