#include "tree.h"
class Solution {
   private:
    queue<TreeNode*> que;
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) return nullptr;
        que.push(root);
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
    }

   public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        root = dfs(root);
        TreeNode* cur = que.front();
        que.pop();
        while (!que.empty()) {
            cur->left = nullptr;
            cur->right = que.front();
            cur = que.front();
            que.pop();
        }
    }
};