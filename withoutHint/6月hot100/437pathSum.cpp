#include "tree.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x),
 * left(left), right(right) {}
 * };
 */
class Solution {
   public:
    int dfs(TreeNode* root, long long targetSum,
            unordered_map<long long, long long>& umap, long long s) {
        if (!root) return 0;
        int ans = 0;
        umap[s]++;
        s += root->val;
        if (umap.count(s - targetSum)) {
            ans += umap[s - targetSum];
        }
        ans += dfs(root->left, targetSum, umap, s);
        ans += dfs(root->right, targetSum, umap, s);
        umap[s - root->val]--;
        return ans;
    }
    int pathSum(TreeNode* root, long long targetSum) {
        unordered_map<long long, long long> umap;
        int ans = 0;
        long long s = 0;
        ans = dfs(root, targetSum, umap, s);
        return ans;
    }
};