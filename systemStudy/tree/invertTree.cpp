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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        // else if (root->left == nullptr && root->right == nullptr)
        //     return root;
        // else if (root->left != nullptr && root->right == nullptr) {
        //     root->left = invertTree(root->left);
        //     return root;
        // } else if (root->left == nullptr && root->right != nullptr) {
        //     root->right == invertTree(root->right);
        //     return root;
        // }
        else {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
    }
};