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
    vector<int> ans;
    void bfs(TreeNode* root) {
        queue<TreeNode*> visited, nextVisit;
        visited.push(root);
        while (!visited.empty()) {
            TreeNode* temp = visited.front();
            visited.pop();
            if (temp->left) nextVisit.push(temp->left);
            if (temp->right) nextVisit.push(temp->right);
            if (visited.empty()) {
                ans.push_back(temp->val);
                visited = nextVisit;
                nextVisit = queue<TreeNode*>();
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return ans;
        bfs(root);
        return ans;
    }
};