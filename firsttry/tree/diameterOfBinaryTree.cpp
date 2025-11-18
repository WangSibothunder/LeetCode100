#include"TreeNode.h"
class Solution {
private:
    int ans;
    int depth(TreeNode* root){
        if (root==nullptr) return 0;
        int L= depth(root->left);
        int R= depth(root->right);
        ans = max(ans,L+R+1);//L+R+1的意思是以这个点为中心左边走到底和右边走到底的最大长度
        return max(L,R)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return --ans;
    }
};