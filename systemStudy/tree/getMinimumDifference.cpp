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
    int ans = INT_MAX;
    int last = INT_MIN;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        last = root->val;
        if (root->left) {
                        ans = min(ans, dfs(root->left) - last);
        }
        if (root->right) {
            ans = min(ans, dfs(root->right) - last);
        }

        return root->val;
    }
    int getMinimumDifference(TreeNode* root) {
        int _ = dfs(root);
        return ans;
    }
};