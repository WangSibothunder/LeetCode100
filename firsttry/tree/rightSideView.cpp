#include "TreeNode.h"
using namespace std;
class Solution {
public:
//BFS，每次只拿每层最右边的节点
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (!root) return ans;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            for(int i = 0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i==sz-1) ans.push_back(node->val);
            }
        }
        return ans;
        
    }
};