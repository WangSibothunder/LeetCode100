#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> minDist, visited;

int main() {
    int V, E;
    cin >> V >> E;
    graph = vector<vector<pair<int, int>>>(V + 1);
    minDist = vector<int>(V + 1, INT_MAX);
    visited = vector<int>(V + 1);
    for (int i = 1; i <= E; i++) {
        int st, ed, dis;
        cin >> st >> ed >> dis;
        graph[st].push_back({ed, dis});
        graph[ed].push_back({st, dis});
    }

    // prim
    int cur = 1;
    minDist[cur] = 0;
    visited[cur] = 1;
    int node = 0;
    while (node < V) {
        visited[cur] = 1;
        // printf("cur:%d\n", cur);
        for (int i = 0; i < graph[cur].size(); i++) {
            if (!visited[graph[cur][i].first] &&
                graph[cur][i].second < minDist[graph[cur][i].first]) {
                minDist[graph[cur][i].first] = graph[cur][i].second;
            }
        }
        int nxt = 0;
        for (int i = 2; i <= V; i++) {
            //   printf("%d ", minDist[i]);
            if (visited[i]) {
                continue;
            } else if (minDist[i] < minDist[nxt])
                nxt = i;
        }
        // cout << "\n";
        node++;
        cur = nxt;
    }
    int ans = 0;
    for (int i = 1; i <= V; i++) ans += minDist[i];
    cout << ans;
    return 0;
}
