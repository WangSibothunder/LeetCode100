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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return ans;
        queue<TreeNode*> cur;
        cur.push(root);
        while (!cur.empty()) {
            queue<TreeNode*> nxt;
            vector<int> temp_ans = {};
            while (!cur.empty()) {
                TreeNode* temp = cur.front();
                cur.pop();
                temp_ans.push_back(temp->val);
                // sum += temp->val;
                if (temp->left) nxt.push(temp->left);
                if (temp->right) nxt.push(temp->right);
            }
            cur = nxt;
            ans.push_back(temp_ans);
        }
        return ans;
    }
};