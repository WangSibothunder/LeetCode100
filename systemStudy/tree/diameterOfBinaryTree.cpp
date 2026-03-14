#include <iostream>
#include <vector>

#include "tree.h"
using namespace std;
class Solution {
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_len = dfs(root->left) + 1;
        int right_len = dfs(root->right) + 1;
        ans = max(ans, left_len + right_len + 1);
        return max(left_len, right_len);
    }

   public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};