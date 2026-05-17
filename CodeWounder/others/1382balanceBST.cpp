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
    vector<TreeNode*> vec;
    void midTran(TreeNode* root) {
        if (root == nullptr) return;
        midTran(root->left);
        vec.push_back(root);
        midTran(root->right);
    }
    TreeNode* buildTree(int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) >> 1;
        vec[mid]->left = buildTree(left, mid - 1);
        vec[mid]->right = buildTree(mid + 1, right);
        return vec[mid];
    }
    TreeNode* balanceBST(TreeNode* root) {
        midTran(root);
        TreeNode* ans = buildTree(0, vec.size() - 1);
        return ans;
    }
};