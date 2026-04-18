#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> graph;
    for (int i = 0; i < M; i++) {
        int st, ed, val;
        scanf("%d %d %d", &st, &ed, &val);
        graph.push_back({st, ed, val});
    }
    vector<int> minDIst(N + 1, INT_MAX);  // 各个节点距离原节点的最短距离
    minDIst[1] = 0;
    for (int i = 1; i <= N; i++) {
        for (auto& ele : graph) {
            int st = ele[0], ed = ele[1], val = ele[2];
            if (minDIst[st] != INT_MAX && minDIst[ed] > minDIst[st] + val) {
                minDIst[ed] = minDIst[st] + val;
            }
        }
    }
    if (minDIst[N] == INT_MAX) {
        cout << "unconnected" << endl;
        return 0;
    }
    cout << minDIst[N] << endl;
    return 0;
}