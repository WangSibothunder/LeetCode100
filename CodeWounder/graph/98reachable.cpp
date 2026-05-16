#include <iostream>
#include <vector>
using namespace std;

vector<int> path;
vector<vector<int>> ans;
void dfs(vector<vector<int>>& graph, int cur, int n) {
    if (cur == n) {
        ans.push_back(path);
        return;
    }
    for (auto& ele : graph[cur]) {
        path.push_back(ele);
        dfs(graph, ele, n);
        path.pop_back();
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    cout << "pass1" << endl;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int st, ed;
        scanf("%d %d", &st, &ed);
        graph[st].push_back(ed);
    }
    cout << "pass2" << endl;
    path.push_back(1);
    dfs(graph, 1, n);
    for (auto& p : ans) {
        for (int i = 0; i < p.size() - 1; i++) printf("%d ", p[i]);
        printf("%d\n", p[p.size() - 1]);
    }
    return 0;
}