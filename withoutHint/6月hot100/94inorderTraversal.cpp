#include "tree.h"

class Solution {
   public:
    vector<int> path;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        path.push_back(root->val);
        dfs(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return path;
    }
};