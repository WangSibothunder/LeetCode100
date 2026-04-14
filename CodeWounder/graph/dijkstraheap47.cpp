#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edges {
    int to, val;
    Edges(int t, int v) : to(t), val(v) {}
};
class mycompare {
   public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<Edges>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int st, ed, val;
        scanf("%d %d %d", &st, &ed, &val);
        Edges temp(ed, val);
        graph[st].push_back(temp);
    }
    vector<int> visited(N + 1), minDist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> minHeap;
    minHeap.push({1, 0});
    minDist[1] = 0;
    while (!minHeap.empty()) {
        int cur = minHeap.top().first,
            val = minHeap.top().second;  // 1. 寻找距离原节点距离最近的节点
        minHeap.pop();
        visited[cur] = 1;  // 2. 加入节点进入路径
        for (auto ele : graph[cur]) {
            if (!visited[ele.to]) {  // 3. 更新minDist中的其他节点
                if (minDist[ele.to] > val + ele.val) {
                    minDist[ele.to] = val + ele.val;
                    minHeap.push({ele.to, minDist[ele.to]});
                }
            }
        }
    }
    if (!visited[N]) {
        cout << -1 << endl;
        return 0;
    }
    cout << minDist[N] << endl;
    return 0;
}