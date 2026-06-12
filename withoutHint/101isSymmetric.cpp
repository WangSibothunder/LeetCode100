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
    void rev(TreeNode* root) {
        if (!root) return;
        swap(root->left, root->right);
        rev(root->left);
        rev(root->right);
    }
    bool match(TreeNode* root1, TreeNode* root2) {
        if (!root1 && root2 || root1->val != root2->val)
            return false;
        else if (!root2 && root1)
            return false;
        else if (!root1 && !root2)
            return true;
        return match(root1->left, root2->left) &&
               match(root1->right, root2->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        rev(root->left);
        return match(root->left, root->right);
    }
};