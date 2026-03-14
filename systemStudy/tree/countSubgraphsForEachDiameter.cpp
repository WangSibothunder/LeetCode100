#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    unordered_map<int, vector<int>> umap;
    vector<int> ans;
    int dfs(int idx) { int deep = 0; }

   public:
    vector<int> countSubgraphsForEachDiameter(int n,
                                              vector<vector<int>>& edges) {
        ans.resize(n, 0);
        for (int i = 0; i < n; i++) {
            if (!umap.count(edges[i][0]))
                umap.insert({edges[i][0], {edges[i][1]}});
            else
                umap[edges[i][0]].push_back(edges[i][1]);
        }
    }
};