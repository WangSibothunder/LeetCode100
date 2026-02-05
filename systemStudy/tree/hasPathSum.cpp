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
    int ans = 0;
    bool isEQ = false;
    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) return;
        ans += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (ans == targetSum) {
                isEQ = true;

            } else {
                ans -= root->val;
            }
            return;
        }
        if (root->left) {
            dfs(root->left, targetSum);
        }
        if (root->right) {
            dfs(root->right, targetSum);
        }
        ans -= root->val;
        return;
    }

   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return isEQ;
    }
};