#include "TreeNode.h"
using namespace std;
class Solution {
    //返回包含root点在那的以root为根节点的节点数目
    int getNodeNum(TreeNode* root){
        int nodeNum = 0;
        if(!root) return nodeNum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            nodeNum++;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return nodeNum;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        while (root)
        {
            int left = getNodeNum(root->left);
            if (left==k-1) break;//这个时候root对应第k大的树；
            else if(left>=k){
                root = root->left;
            } else{
                k = k-left-1;
                root = root->right;
            }
        }
        return root->val;
        
    }
};