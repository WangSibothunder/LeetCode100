#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> father;
    void init(int n) {
        for (int i = 0; i < n; i++) {
            father.push_back(i);
        }
    }
    int find(int u) {
        if (u == father[u]) return u;
        return father[u] = find(father[u]);
    }
    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[u] = v;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            if (isSame(edges[i][0], edges[i][1])) {
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return {-1, -1};
    }
};