#include "tree.h"
class Solution {
   public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth = 0, rightDepth = 0;
        TreeNode* cur = root;
        while (cur->left) {
            leftDepth++;
            cur = cur->left;
        }
        cur = root;
        while (cur->right) {
            rightDepth++;
            cur = cur->right;
        }
        int re = 0;
        if (leftDepth == rightDepth)
            re = 2 << leftDepth;
        else
            re = countNodes(root->left) + countNodes(root->right) + 1;
        return re;
    }
};