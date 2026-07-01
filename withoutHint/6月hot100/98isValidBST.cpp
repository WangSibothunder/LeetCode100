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
    vector<int> path;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool re = true;
        re &= isValidBST(root->left);
        path.push_back(root->val);
        if (path.size() > 1 && path[path.size() - 1] <= path[path.size() - 2])
            return false;
        re &= isValidBST(root->right);
        return re;
    }
};