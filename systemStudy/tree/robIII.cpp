#include "tree.h"
class Solution {
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto [l_rob, l_n_rob] = dfs(root->left);
        auto [r_rob, r_n_rob] = dfs(root->right);
        int rob = root->val + l_n_rob + r_n_rob;
        int n_rob = max(l_n_rob, l_rob) + max(r_n_rob, r_rob);
        return {rob, n_rob};
    }

   public:
    int rob(TreeNode* root) {
        auto [rob, n_rob] = dfs(root);
        return max(rob, n_rob);
    }
};