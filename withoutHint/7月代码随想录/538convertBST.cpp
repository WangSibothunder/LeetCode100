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
    int pre = INT_MIN;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->right);
        if (pre != INT_MIN) root->val += pre;
        pre = root->val;
        dfs(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};