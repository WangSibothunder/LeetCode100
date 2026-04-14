#include <iostream>
#include <vector>
using namespace std;
int n = 1005;
vector<int> father(n);
void init() {
    for (int i = 0; i < n; i++) father[i] = i;
}
int find(int u) {  // 返回u的根结点
    if (u == father[u]) return u;
    return father[u] = find(father[u]);
}
bool isSame(int u, int j) {  // 判断u和j是否是同一个根结点
    u = find(u);
    j = find(j);
    return u == j;
}
void join(int u, int v) {  // 将v->u 这条边加入并查集
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[v] = u;
}
int main() {
    init();
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        join(u, v);
    }
    int source, desternation;
    scanf("%d %d", &source, &desternation);
    int re = isSame(source, desternation);
    cout << re << endl;
    return 0;
}