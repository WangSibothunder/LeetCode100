#include "tree.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* ans = nullptr;
    pair<bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return make_pair(0, 0);
        }
        bool find_p = 0, find_q = 0;
        if (root == p) find_p = 1;
        if (root == q) find_q = 1;
        bool left_find_p = 0, left_find_q = 0;
        bool right_find_p = 0, right_find_q = 0;
        if (root->left) {
            pair<bool, bool> left = dfs(root->left, p, q);
            left_find_p = left.first;
            left_find_q = left.second;
        }
        if (root->right) {
            pair<bool, bool> right = dfs(root->right, p, q);
            right_find_p = right.first;
            right_find_q = right.second;
        }
        find_p = find_p || left_find_p || right_find_p;
        find_q = find_q || left_find_q || right_find_q;
        if (find_p && find_q) {
            if (ans == nullptr) ans = root;
        }
        return make_pair(find_p, find_q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};