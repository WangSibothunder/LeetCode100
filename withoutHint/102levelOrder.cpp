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
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        queue<TreeNode*> queTemp;
        while (!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            path.push_back(temp->val);
            if (temp->left) queTemp.push(temp->left);
            if (temp->right) queTemp.push(temp->right);
            if (que.empty()) {
                que = queTemp;
                queTemp = queue<TreeNode*>();
                ans.push_back(path);
                path = vector<int>();
            }
        }
        return ans;
    }
};