#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int V, E;
struct Edge {
    int l, r, val;
};

int n = 1005;
vector<int> father(n);
void init() {
    for (int i = 1; i < n; i++) father[i] = i;
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

int main() {
    scanf("%d %d", &V, &E);
    vector<Edge> graph;
    for (int i = 0; i < E; i++) {
        Edge temp;
        scanf("%d %d %d", &temp.l, &temp.r, &temp.val);
        graph.push_back(temp);
    }
    sort(graph.begin(), graph.end(),
         [](Edge& a, Edge& b) { return a.val < b.val; });
    init();
    int re = 0;
    for (auto ele : graph) {
        if (!isSame(ele.l, ele.r)) {
            join(ele.l, ele.r);
            re += ele.val;
        }
    }
    cout << re << endl;
    return 0;
}