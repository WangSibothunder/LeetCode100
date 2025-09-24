#include"TreeNode.h"
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* node = stack.top();stack.pop();
            if(node->right) stack.push(node->right);
            if(node->left) stack.push(node->left);
            swap(node->left,node->right); 
        }
        return root;
    }
};