#include <iostream>
#include <vector>
using namespace std;
int n = 1005;
vector<int> father(n, 0);
void init() {
    for (int i = 0; i < n; i++) father[i] = i;
}
int find(int u) {
    if (father[u] == u) return u;
    return father[u] = find(father[u]);
}
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[u] = v;
}
int main() {
    int N;
    scanf("%d", &N);
    init();
    for (int i = 0; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (isSame(u, v)) {
            printf("%d %d\n", u, v);
            return 0;
        }
        join(u, v);
    }
    return 0;
}