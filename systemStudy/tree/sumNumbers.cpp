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
    int singleSum = 0, ansSum = 0;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        singleSum = singleSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            ansSum += singleSum;
            singleSum -= root->val;
            singleSum /= 10;
            return;
        }
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        singleSum -= root->val;
        singleSum /= 10;
        return;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return ansSum;
    }
};