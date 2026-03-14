#include "tree.h"
class Solution {
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_sum = dfs(root->left);
        int right_sum = dfs(root->right);
        ans = max(ans, max(0, left_sum) + max(0, right_sum) + root->val);
        return root->val + max(max(left_sum, right_sum), 0);
    }

   public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};