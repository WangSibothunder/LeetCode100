#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, K;

void dfs(vector<vector<int>>& graph, vector<bool>& visit, int cur) {
    // if (graph[cur].size() == 0) return;
    for (int i = 0; i < graph[cur].size(); i++) {
        int nxt = graph[cur][i];
        if (visit[nxt] == 0) {
            visit[nxt] = 1;
            dfs(graph, visit, nxt);
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    vector<vector<int>> graph(N + 1);
    vector<bool> visit(N + 1);
    for (int i = 0; i < K; i++) {
        int st, ed;
        scanf("%d %d", &st, &ed);
        graph[st].push_back(ed);
    }
    visit[1] = 1;
    dfs(graph, visit, 1);
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}