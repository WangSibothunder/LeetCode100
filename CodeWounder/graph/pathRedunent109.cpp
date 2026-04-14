#include <iostream>
// #include <pair>
#include <vector>
using namespace std;
int n = 1005;
vector<int> father(n);
void init() {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}
int find(int u) {
    if (father[u] == u) return u;
    return father[u] = find(father[u]);
}
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return (u == v);
}
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[u] = v;
}

bool isTreeAfterRemove(vector<vector<int>>& graph, int deleteEdge) {
    init();
    for (int i = 1; i < graph.size(); i++) {
        // 删除的是起点对应的边（指出）
        if (i == deleteEdge) continue;
        for (auto ele : graph[i]) {
            if (isSame(i, ele)) {
                return false;  // 未加入图就存在，说明有环
            }
            join(i, ele);
        }
    }
    return true;
}

void findCycle(vector<vector<int>>& graph) {
    init();
    for (int i = 1; i < graph.size(); i++) {
        for (auto ele : graph[i]) {
            if (isSame(i, ele)) {
                printf("%d %d\n", i, ele);
                return;
            }
            join(i, ele);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    vector<vector<int>> graph(N + 1);
    vector<int> degree(N, 0);
    int nodeTwoDegree;
    vector<pair<int, int>> nodeWithTwoDegree;
    for (int i = 1; i <= N; i++) {
        int st, ed;
        scanf("%d %d", &st, &ed);
        graph[st].push_back(ed);  // st->ed,
        degree[ed]++;
        if (degree[ed] >= 2) nodeTwoDegree = ed;  // st->ed
    }
    for (int i = 1; i < graph.size(); i++) {
        for (auto ele : graph[i]) {
            if (ele == nodeTwoDegree) nodeWithTwoDegree.push_back({i, ele});
        }
    }
    for (int i = nodeWithTwoDegree.size() - 1; i >= 0; i--) {
        if (isTreeAfterRemove(graph, nodeWithTwoDegree[i].first)) {
            printf("%d %d\n", nodeWithTwoDegree[i].first,
                   nodeWithTwoDegree[i].second);
            return 0;
        }
    }
    findCycle(graph);
    return 0;
}