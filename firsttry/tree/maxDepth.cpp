#include"TreeNode.h"
using namespace std;
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while(!Q.empty()){//树没有遍历完全
            int sz = Q.size();//sz记录的是当前曾的节点数
            while(sz>0){
                TreeNode* node = Q.front();Q.pop();
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
                sz--;
            }
            ans++;//上面数了每一层的变化；
        }
        return ans;
    }
};