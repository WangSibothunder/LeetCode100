#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;

int main() {
    scanf("%d %d", &N, &M);
    vector<vector<int>> graph(N);
    vector<int> inDegree(N);
    for (int i = 0; i < M; i++) {
        int st, ed;
        scanf("%d %d", &st, &ed);
        graph[st].push_back(ed);
        inDegree[ed]++;
    }
    queue<int> zeroInDegree, ans;
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) {
            // visited[i] = 1;
            zeroInDegree.push(i);
        }
    }
    bool flag = 0;
    while (!zeroInDegree.empty()) {
        int cur = zeroInDegree.front();
        ans.push(cur);
        zeroInDegree.pop();
        // if (flag == 0) {
        //     printf("%d", cur);
        //     flag = 1;
        // } else
        //     printf(" %d", cur);
        for (auto ele : graph[cur]) {
            // if (!visited[ele]) {
            // visited[ele] = 1;
            inDegree[ele]--;
            if (inDegree[ele] == 0) zeroInDegree.push(ele);
            // }
        }
    }
    if (ans.size() != N) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        int temp = ans.front();
        ans.pop();
        if (i != N - 1)
            printf("%d ", temp);
        else
            printf("%d\n", temp);
    }
    return 0;
}