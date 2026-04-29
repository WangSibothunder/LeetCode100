#include "tree.h"
class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> que;
        if (root == nullptr) return ans;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size - 1; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            TreeNode* cur = que.front();
            ans.push_back(cur->val);
            que.pop();
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
            // ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};