#include "tree.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* ans = nullptr;
    unordered_map<TreeNode*, int> has_p, has_q;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return;
        if (root == p) has_p[root] = 1;
        if (root == q) has_q[root] = 1;
        dfs(root->left, p, q);
        dfs(root->right, p, q);
        if (has_p[root->left] || has_p[root->right]) has_p[root] = 1;
        if (has_q[root->left] || has_q[root->right]) has_q[root] = 1;
        if (ans == nullptr && has_p[root] && has_q[root]) ans = root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};