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
    bool flag = 0;
    int dfs(TreeNode* root) {
        if (!root || flag) return 0;
        if (abs(dfs(root->left) - dfs(root->right)) > 1) {
            cout << root->val;
            flag = 1;
            return 0;
        } else
            return max(dfs(root->left), dfs(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return !flag;
    }
};