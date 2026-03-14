#include "tree.h"
class Solution {
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_len = 0;
        left_len = dfs(root->left);
        if (root->left && root->left->val != root->val) left_len = 0;
        int right_len = 0;
        right_len = dfs(root->right);
        if (root->right && root->right->val != root->val) right_len = 0;
        ans = max(ans, left_len + right_len + 1);
        return max(left_len, right_len) + 1;
    }

   public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};