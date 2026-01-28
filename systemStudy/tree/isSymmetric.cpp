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
    TreeNode* reverseNode(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        reverseNode(root->left);
        reverseNode(root->right);
        return root;
    }
    bool isSame(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        else if ((root1 == nullptr && root2 != nullptr) ||
                 (root1 != nullptr && root2 == nullptr))
            return false;
        return isSame(root1->left, root2->left) &&
               isSame(root1->right, root2->right) && (root1->val == root2->val);
    }
    bool isSymmetric(TreeNode* root) {
        // 反转root->left与root->right 判断相同，两个题目缝合
        TreeNode* reverseLeft = reverseNode(root->left);
        return isSame(reverseLeft, root->right);
    }
};