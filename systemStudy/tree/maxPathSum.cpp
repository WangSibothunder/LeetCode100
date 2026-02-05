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
    int ans = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = 0, right = 0;
        if (root->left) left = max(dfs(root->left), 0);
        if (root->right) right = max(dfs(root->right), 0);
        ans = max(ans, max(max(root->val + left, root->val + right),
                           root->val + left + right));
        return max(root->val + left, root->val + right);
    }

   public:
    int maxPathSum(TreeNode* root) {
        int _ = dfs(root);
        return ans;
    }
};