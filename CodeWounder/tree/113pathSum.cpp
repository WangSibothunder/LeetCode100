#include "tree.h"
class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) {  // when root is nullptr
            if (targetSum == 0) ans.push_back(path);
            return;
        }
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            ans.push_back(path);
            return;
        }
        if (root->left) dfs(root->left, targetSum);
        if (root->right) dfs(root->right, targetSum);
        path.pop_back();
        targetSum += root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};