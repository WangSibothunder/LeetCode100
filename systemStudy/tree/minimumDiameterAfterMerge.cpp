#include <iostream>
#include <vector>

#include "tree.h"
using namespace std;

class Solution {
    int ans = 0;
    int n = 0;
    int m = 0;
    // vector<int> tree1_leftmax, tree1_rightmax, tree2_leftmax, tree2_rightmax;
    int tree1_max = 0, tree2_max = 0;
    unordered_map<int, vector<int>> umapTree1, umapTree2;
    int dfs1(int idx) {
        int left_max = 0, right_max = 0;
        for (int i = 0; i < umapTree1[idx].size(); i++) {
            int temp = dfs1(umapTree1[idx][i]);
            if (temp > left_max) {
                right_max = left_max;
                left_max = temp;
            } else if (temp > right_max)
                right_max = temp;
        }
        // tree1_leftmax[idx] = left_max;
        // tree1_rightmax[idx] = right_max;
        tree1_max = max(max(left_max, right_max), tree1_max);
        return max(left_max, right_max) + 1;
    }
    int dfs2(int idx) {
        int left_max = 0, right_max = 0;
        for (int i = 0; i < umapTree2[idx].size(); i++) {
            int temp = dfs2(umapTree2[idx][i]);
            if (temp > left_max) {
                right_max = left_max;
                left_max = temp;
            } else if (temp > right_max)
                right_max = temp;
        }
        // tree2_leftmax[idx] = left_max;
        // tree2_rightmax[idx] = right_max;
        tree2_max = max(max(left_max, right_max), tree2_max);
        return max(left_max, right_max) + 1;
    }

   public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        this->n = edges1.size();
        this->m = edges2.size();
        // tree1_leftmax.resize(n, 0);
        // tree1_rightmax.resize(n, 0);
        // tree2_leftmax.resize(m, 0);
        // tree2_rightmax.resize(m, 0);
        for (int i = 0; i < n; i++) {
            if (!umapTree1.count(edges1[i][0]))
                umapTree1.insert({edges1[i][0], {edges1[i][1]}});
            else
                umapTree1[edges1[i][0]].push_back(edges1[i][1]);
        }
        for (int i = 0; i < m; i++) {
            if (!umapTree2.count(edges2[i][0]))
                umapTree2.insert({edges2[i][0], {edges2[i][1]}});
            else
                umapTree2[edges2[i][0]].push_back(edges2[i][1]);
        }
        dfs1(0);
        dfs2(0);
        return tree1_max + tree2_max + 2;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {0, 3}, {2, 4},
                                  {2, 5}, {3, 6}, {2, 7}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 4},
                                  {2, 5}, {3, 6}, {2, 7}};
    int result = sol.minimumDiameterAfterMerge(edges1, edges2);
    cout << "Result: " << result << endl;
    return 0;
}