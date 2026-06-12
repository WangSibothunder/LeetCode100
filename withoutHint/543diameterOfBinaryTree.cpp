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
    int ans = 0;
    int dst(TreeNode* root) {
        if (!root) return 0;
        int left_reach = dst(root->left), right_reach = dst(root->right);
        ans = max(ans, left_reach + 1 + right_reach);
        return max(left_reach, right_reach) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dst(root);
        return ans - 1;
    }
};