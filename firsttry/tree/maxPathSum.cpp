#include "TreeNode.h"
using namespace std;
class Solution
{
private:
    int maxsum = INT_MIN;
    int maxdfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxLeft = max(maxdfs(root->left), 0);
        int maxRight = max(maxdfs(root->right), 0);
        int maxCurent = root->val + maxLeft + maxRight;//这个计算的是当前节点作为根节点从左往右的最值
        maxsum = max(maxsum, maxCurent);
        return root->val+max(maxLeft,maxRight);//这里体现出路径选择
    }

public:
    int maxPathSum(TreeNode *root)
    {
        maxdfs(root);
        return maxsum;
    }
};