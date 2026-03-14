#include <iostream>
#include <unordered_map>
#include <vector>
// #include<pair>
using namespace std;
unordered_map<int, vector<int>> umap;
vector<int> f;
pair<int, int> dfs(int idx) {
    if (!umap.count(idx)) return {0, 0};
    int n = umap[idx].size();
    // vector<int> child_rob(n),child_n_rob(n);
    int child_rob = 0, child_n_rob = 0;
    for (int i = 0; i < n; i++) {
        auto [rob, n_rob] = dfs(umap[idx][i]);
        child_rob += n_rob;
        child_n_rob += max(n_rob, rob);
    }
    child_rob += f[idx];
    return {child_rob, child_n_rob};
}
int main() {
    int n;
    cin >> n;
    f.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    int u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        if (!umap.count(v))
            umap.insert({v, {u}});
        else
            umap[v].push_back(u);
    }
    auto [rob, n_rob] = dfs(v);
    return max(rob, n_rob);
}
