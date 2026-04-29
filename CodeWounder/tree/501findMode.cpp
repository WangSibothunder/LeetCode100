#include "tree.h"
class Solution {
   public:
    vector<int> result;
    TreeNode* pre = nullptr;
    int cnt = 0, maxCnt = 0;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        cout << root->val << endl;
        if (root->left) dfs(root->left);
        if (root->left == nullptr && pre == nullptr) {
            pre = root;
            // return;
        } else if (pre->val == root->val)
            cnt++;
        else {
            if (cnt > maxCnt) {
                maxCnt = cnt;
                result.clear();
                result.push_back(pre->val);
            } else if (cnt == maxCnt) {
                result.push_back(pre->val);
            }
            pre = root;
            cnt = 0;
        }
        if (root->right) dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        if (cnt > maxCnt) {
            maxCnt = cnt;
            result.clear();
            result.push_back(pre->val);
        } else if (cnt == maxCnt) {
            result.push_back(pre->val);
        }
        return result;
    }
};