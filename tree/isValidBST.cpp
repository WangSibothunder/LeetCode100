#include "TreeNode.h"
using namespace std;
class Solution {
public:
    /*
    中序遍历之后比大小
    */
    bool isValidBST(TreeNode* root) {
        stack <TreeNode*> stk;
        long long tempmax = (long long) INT_MIN-1;
        while(!stk.empty()||root){
            while(root){//追寻左侧最底
                stk.push(root);
                root = root->left;
            } root = stk.top();
            stk.pop();
            if(root->val<=tempmax) return false;
            tempmax = root->val;
            root = root->right;
        } return true;
    }
};