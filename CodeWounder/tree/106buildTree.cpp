#include "tree.h"
class Solution {
   public:
    unordered_map<int, int> idx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, postorder);
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() && postorder.empty()) return nullptr;
        TreeNode* midRoot = new TreeNode(postorder.back());
        int index;
        for (index = 0;
             index < inorder.size() && inorder[index] != postorder.back();
             index++);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index + 1);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
        vector<int> leftPostorder(postorder.begin(),
                                  postorder.begin() + index + 1);
        vector<int> rightPostorder(postorder.begin() + index + 1,
                                   postorder.end() - 1);
        midRoot->left = dfs(leftInorder, leftPostorder);
        midRoot->right = dfs(rightInorder, rightPostorder);
    }
};