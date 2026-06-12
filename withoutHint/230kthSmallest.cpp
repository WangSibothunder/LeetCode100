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
    vector<int> visited;
    int len = 0;
    void visit(TreeNode* root, int k) {
        if (!root || len == k) return;
        visit(root->left, k);
        visited.push_back(root->val);
        len++;
        visit(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        visit(root, k);
        return visited[k - 1];
    }
};