#include "TreeNode.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            int sz=Q.size();
            vector<int> tempans;
            for(int i = 0; i<sz;i++){
                TreeNode* temp = Q.front();
                Q.pop();
                tempans.push_back(temp->val);
                if(temp->left) Q.push(temp->left);
                if(temp->right) Q.push(temp->right);
            }
            ans.push_back(tempans);
        }
        return ans;
    }
};