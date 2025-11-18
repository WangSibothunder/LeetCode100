#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        // 将右子树翻折，观察是否对称
        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(root); // 这一步是由于我们需要从根节点开始翻折
        while (!Q.empty())
        {
            TreeNode *node1 = Q.front();
            Q.pop();
            TreeNode *node2 = Q.front();
            Q.pop();
            // 由于必须要存进去nullptr，因此需要检验这次存的两个是不是都是ptr
            if (node1 == nullptr && node2 == nullptr)
                continue;
            else if ((node1 == nullptr || node2 == nullptr) || (node1->val != node2->val))
                return false;
            Q.push(node1->left);
            Q.push(node2->right);
            Q.push(node1->right);
            Q.push(node2->left);
        }
        return true;
    }
};