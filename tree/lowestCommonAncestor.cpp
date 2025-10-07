#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;                                           // 包含两种情况，一种没找到，一种找到
        TreeNode *left = lowestCommonAncestor(root->left, p, q);   // 在左子树递归
        TreeNode *right = lowestCommonAncestor(root->right, p, q); // 在右子树递归
        if (left && right)
            return root;            // 左右都找到的话就一层一层往上传
        return left ? left : right; // 只在左子树或者右子树找到就
    }
};