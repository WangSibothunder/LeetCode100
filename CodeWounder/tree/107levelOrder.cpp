#include "tree.h"
class Solution {
   public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if (root == nullptr) return ans;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};