#include <iostream>
#include <ranges>
#include <vector>
using namespace std;

int V, E;

int main() {
    scanf("%d %d", &V, &E);
    vector<vector<int>> graph(V + 1,
                              vector<int>(V + 1, 10001));  // 邻接矩阵存放边的权
    for (int i = 0; i < E; i++) {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);
        graph[u][v] = k;
        graph[v][u] = k;
    }
    vector<int> minDist(V + 1, 10001), inTree(V + 1, 0);
    inTree[1] = 1;
    minDist[0] = 0;
    minDist[1] = 0;  // 节点一作为树的起点
    for (int i = 2; i <= V; i++) {
        minDist[i] = graph[1][i];  // 节点一进入后更新
    }

    for (int node = 2; node <= V; node++) {  // 剩下2-V的节点没有接入树
        int inTree_min = 10001, inTree_min_node;
        for (int find_min = 1; find_min <= V; find_min++) {  // 1.选择最小的距离
            if (!inTree[find_min] &&
                minDist[find_min] <
                    inTree_min) {  // 下表为inTree_min_node表示树中最近的节点
                inTree_min = minDist[find_min];
                inTree_min_node = find_min;
            }
        }
        inTree[inTree_min_node] = 1;  // 2.将最近节点加入树中
        for (int i = 1; i <= V; i++) {
            if (!inTree[i]) {  // 3.未在树中的需要更新距离树的最短距离
                if (graph[inTree_min_node][i] < minDist[i])
                    minDist[i] = graph[inTree_min_node][i];
            }
        }
    }
    int re = 0;
    for (int i = 1; i <= V; i++) re += minDist[i];
    cout << re << endl;
    return 0;
}