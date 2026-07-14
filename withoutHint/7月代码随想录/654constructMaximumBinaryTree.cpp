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
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if (left >= nums.size() || right < 0 || left > right) return nullptr;
        int idx = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > nums[idx]) idx = i;
        }
        cout << idx << endl;
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = dfs(nums, left, idx - 1);
        root->right = dfs(nums, idx + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};