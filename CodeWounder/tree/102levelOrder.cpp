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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que, temp;
        vector<vector<int>> ans;
        // vector<int> temp;
        if (root == nullptr) return ans;
        que.push(root);
        ans.push_back({root->val});
        if (root->left == nullptr && root->right == nullptr) return ans;
        ans.push_back({});
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur->left) {
                ans.back().push_back(cur->left->val);
                temp.push(cur->left);
            }
            if (cur->right) {
                ans.back().push_back(cur->right->val);
                temp.push(cur->right);
            }
            if (!temp.empty() && que.empty()) {
                que, temp = temp, que;
                ans.push_back({});
            }
        }
        return ans;
    }
};