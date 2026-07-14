#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
void bfs(int st) {
    visited[st] = 1;
    queue<int> myque, temp;
    myque.push(st);
    while (!myque.empty()) {
        int cur = myque.front();
        visited[cur] = 1;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (visited[graph[cur][i]] == 0) temp.push(graph[cur][i]);
        }
        if (myque.empty()) {
            myque = temp;
            temp = queue<int>();
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    graph = vector<vector<int>>(n + 1);
    visited = vector<int>(n + 1);
    for (int i = 0; i <= m; i++) {
        int st, ed;
        cin >> st >> ed;
        cout << st << " " << ed << "\n";
        graph[st].push_back(ed);
    }
    bfs(1);
    // int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            cout << -1;
            return 0;
        }
    }
    cout << 1;
    return 0;
}