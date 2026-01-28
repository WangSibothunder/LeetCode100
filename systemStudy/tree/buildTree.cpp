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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        if (preorder.size() == 1)
            return new TreeNode(preorder[0]);  // 队伍中就只有这一个
        TreeNode* root = new TreeNode(preorder.front());
        auto inorder_root_iter = find(
            inorder.begin(), inorder.end(),
            preorder
                .front());  // 中序遍历里面这个点左侧是左子树，右侧是右子树，*(inorder_root_iter-1)是前序遍历左子树结束的位置
        // vector<int> inorder_left = {};
        // vector<int> inorder_right = {};  // 需要特别判断没有左子树的情况
        vector<int> inorder_left(inorder.begin(),
                                 inorder_root_iter);  // 起点到root左侧
        vector<int> inorder_right(inorder_root_iter + 1,
                                  inorder.end());  // root右侧到终点
        vector<int> preorder_left = {};
        vector<int> preorder_right = {};
        if (inorder_root_iter != inorder.begin()) {
            auto preorder_left_iter =
                find(preorder.begin(), preorder.end(),
                     *(inorder_root_iter -
                       1));  // 从【1】到preorder_left_iter都是左子树;
            if (inorder_root_iter != inorder.begin() + 1 &&
                find(inorder.begin(), inorder.end(), *(preorder.begin() + 1)) ==
                    inorder_root_iter - 1)
            // 第一种情况，左子树的右子子树存在
            {
                preorder_left_iter =
                    find(preorder.begin(), preorder.end(),
                         *(inorder_root_iter -
                           2));  // 从【1】到preorder_left_iter都是左子树
            }

            preorder_left =
                vector<int>(preorder.begin() + 1,
                            preorder_left_iter + 1);  // 起点到root左侧
            preorder_right = vector<int>(preorder_left_iter + 1,
                                         preorder.end());  // root右侧到终点
        } else
            preorder_right = vector<int>(preorder.begin() + 1, preorder.end());
        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);
        return root;
    }
};