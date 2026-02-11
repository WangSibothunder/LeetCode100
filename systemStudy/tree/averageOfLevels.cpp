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
    vector<double> ans = {};
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) return ans;
        queue<TreeNode*> cur;
        cur.push(root);
        while (!cur.empty()) {
            queue<TreeNode*> nxt;
            double sum = 0;
            double lenth = cur.size();
            while (!cur.empty()) {
                TreeNode* temp = cur.front();
                cur.pop();
                sum += temp->val;
                if (temp->left) nxt.push(temp->left);
                if (temp->right) nxt.push(temp->right);
            }
            cur = nxt;
            ans.push_back(sum / lenth);
        }
        return ans;
    }
};