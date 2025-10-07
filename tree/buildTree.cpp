#include "TreeNode.h"
using namespace std;

class Solution {
private:
    unordered_map<int, int> index;
    //递归处理，得到前序遍历的子段与中序遍历的子段，辨认出当前根节点并且构建其叶子
    TreeNode* myBuildTree(vector<int>& preorder,vector<int>& inorder, int preleft, int preright,int inleft,int inright){
        if(preleft>preright) return nullptr;//这个时候左子树已经到底了
        TreeNode* root = new TreeNode(preorder[preleft]);//前序遍历的第一个节点是根节点
        int inorder_root_index = index[preorder[preleft]];//得到中序遍历根节点的位置
        int lefttree_length = inorder_root_index-inleft;//左子树的长度是中序遍历的起点到根节点左侧
        root->left = myBuildTree(preorder,inorder,preleft+1,preleft+lefttree_length,inleft,inorder_root_index-1);//递归左子树
        root->right = myBuildTree(preorder,inorder,preleft+lefttree_length+1,preright,inorder_root_index+1,inright);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //先构建哈希表，用节点的值定位中序遍历的坐标
        int n = preorder.size();
        for(int i = 0;i<n;i++){
            index[inorder[i]] = i;//这个字典存储着下标
        }  
        return myBuildTree(preorder,inorder,0,n-1,0,n-1);
    }
};

