#include "TreeNode.h"
using namespace std;
class Solution {
    unordered_map<long long,int> prefix;
    /*
    深搜前缀和：
    # Args:
         **root** :当前根节点
         **curr** :到当前节点累计前缀和
         **targetSum** :指定的和
    */
    int dfs(TreeNode* root, int curr,int targetSum){
        if(!root) return 0;//空节点无法贡献有效数字
        curr+=root->val;//累加前缀
        int ret = 0;//ret代表的是到这个节点为止有多少符合targetSum要求的路径
        if(prefix.count(curr-targetSum)) ret = prefix[curr-targetSum];//curr累加的当前一条路走到黑的，所以相减
        prefix[curr]++;
        ret+=dfs(root->left,curr,targetSum);
        ret+=dfs(root->right,curr,targetSum);
        prefix[curr]--;//递归返回时，不要考虑已经计算过的节点
        return ret;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0]=1;//初始化前缀和0为1,全部加起来一样算一条路
        return dfs(root,0,targetSum);
    }
};