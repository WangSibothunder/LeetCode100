#include "tree.h"
class Solution {
   public:
    TreeNode* ans = nullptr;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return 0;
        int reRoot = root == p || root == q;
        int reLeft = dfs(root->left, p, q);
        int reRight = dfs(root->right, p, q);
        if (ans == nullptr && (reRight + reRoot + reLeft) == 2) ans = root;
        return reLeft || reRight || reRoot;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool re = dfs(root, p, q);
        return ans;
    }
};