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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return ans;
        queue<TreeNode*> myque, temp;
        myque.push(root);
        while (!myque.empty()) {
            TreeNode* tempNode = myque.front();
            path.push_back(tempNode->val);
            myque.pop();
            if (tempNode->left) temp.push(tempNode->left);
            if (tempNode->right) temp.push(tempNode->right);
            if (myque.empty()) {
                myque = temp;
                temp = queue<TreeNode*>();
                ans.push_back(path);
                path = vector<int>();
            }
        }
        return ans;
    }
};