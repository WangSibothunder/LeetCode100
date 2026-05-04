#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> dfs(
        TreeNode* root) {  // int nodeValue[2] = {rob cur,not rob cur}
        vector<int> nodeValue = {0, 0};
        if (!root) return nodeValue;
        vector<int> leftValue = dfs(root->left);
        vector<int> rightValue = dfs(root->right);
        nodeValue[0] = root->val + leftValue[1] + rightValue[1];
        nodeValue[1] =
            max(leftValue[0], leftValue[1]) + max(rightValue[0], rightValue[1]);
        return nodeValue;
    }
    int rob(TreeNode* root) {
        vector<int> nodeValue = dfs(root);
        return max(nodeValue[0], nodeValue[1]);
    }
};