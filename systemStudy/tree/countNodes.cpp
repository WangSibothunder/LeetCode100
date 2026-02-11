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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> cur;
        cur.push(root);
        int ans = 0;
        if (!root) return ans;
        while (!cur.empty()) {
            queue<TreeNode*> nxt;
            while (!cur.empty()) {
                TreeNode* temp = cur.front();
                cur.pop();
                ++ans;
                if (temp->left) nxt.push(temp->left);
                if (temp->right) nxt.push(temp->right);
            }
            cur = nxt;
        }
        return ans;
    }
};