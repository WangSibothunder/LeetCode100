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
    int ans = INT_MIN;
    int dfs(TreeNode* root) {
        // 返回【self】+最大的一个子树
        if (!root) return 0;
        int re = root->val;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        int sum = re + left + right;
        if (ans < sum) ans = sum;
        return re + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};