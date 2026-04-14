#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INT_MAX));
    vector<int> visited(N + 1), minDist(N + 1, INT_MAX);
    for (int i = 1; i <= M; i++) {
        int st, ed, val;
        scanf("%d %d %d", &st, &ed, &val);
        graph[st][ed] = val;
        // graph[st][st] = 0;
    }
    int st = 1, ed = N;
    minDist[1] = 0;
    for (int time = 0; time < N; time++) {
        // 最多排序N个点的链表
        int min_node = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && minDist[i] < minDist[min_node]) {
                // 1.寻找minDist中里原节点距离最小的节点
                min_node = i;
            }
        }
        // 2.将该节点加入树
        visited[min_node] = 1;
        // 3.更新minDist各节点的值
        for (int i = 1; i <= N; i++) {
            if (graph[min_node][i] != INT_MAX) {
                minDist[i] =
                    min(minDist[i], graph[min_node][i] + minDist[min_node]);
            }
        }
    }
    if (!visited[ed]) {
        printf("%d\n", -1);
        return 0;
    }
    printf("%d\n", minDist[ed]);
    return 0;
}