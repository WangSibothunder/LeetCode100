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
    vector<int> preorder;
    vector<int> inorder;
    TreeNode* buildTree(int preSt, int preEd, int inSt, int inEd) {
        if (preSt >= preEd) return new TreeNode(preorder[preSt]);
        TreeNode* root = new TreeNode(preorder[preSt]);
        int i;
        for (i = inSt; i <= inEd; i++) {
            if (inorder[i] == preorder[preSt]) {
                break;
            }
        }
        root->left = buildTree(preSt + 1, preSt + (i - inSt), inSt, i - 1);
        root->right = buildTree(preSt + (i - inSt) + 1, preEd, i + 1, inEd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
        this->preorder = preorder;
        this->inorder = inorder;
        TreeNode* ans = buildTree(0, n - 1, 0, n - 1);
        return ans;
    }
};