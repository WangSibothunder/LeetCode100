#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int to, val;
    Edge(int t, int v) : to(t), val(v) {}
};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    Edge temp(0, 0);
    vector<vector<Edge>> graph(N + 1);
    int st;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &st, &temp.to, &temp.val);
        graph[st].push_back(temp);
    }
    queue<int> BMFD;
    vector<bool> inQueue(N + 1);
    vector<int> minDist(N + 1, INT_MAX);
    minDist[1] = 0;
    BMFD.push(1);
    inQueue[1] = 1;
    while (!BMFD.empty()) {
        int st = BMFD.front();
        BMFD.pop();
        inQueue[st] = 0;
        for (auto& edge : graph[st]) {
            if (minDist[edge.to] > minDist[st] + edge.val) {
                if (!inQueue[edge.to]) {
                    BMFD.push(edge.to);
                    inQueue[edge.to] = 1;
                }
                minDist[edge.to] = minDist[st] + edge.val;
            }
        }
    }
    if (minDist[N] == INT_MAX)
        cout << "unconnected" << endl;  // 不能到达终点
    else
        cout << minDist[N] << endl;  // 到达终点最短路径
    return 0;
}