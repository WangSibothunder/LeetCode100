#include "TreeNode.h"
using namespace std;
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur!=nullptr) {
            TreeNode* next = cur->left;//假如没有左子树怎么办
            if(next){
                TreeNode* depthright = next;
                while(depthright->right) depthright = depthright->right;//得到左子树的最大右节点
                depthright->right = cur->right;//将根节点的右子树放到左子树最右侧节点的右侧；
                cur->left=nullptr;//断开根节点的左子树
                cur->right = next;
            } cur = cur->right;
             
        }
    }
};