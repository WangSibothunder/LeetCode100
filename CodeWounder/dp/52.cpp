#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, v;
    scanf("%d %d", &n, &v);
    vector<int> weights(n), values(n);
    vector<vector<int>> f(n + 1, vector<int>(v + 1));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v; j++) {
            if (weights[i - 1] > j)
                f[i][j] = f[i - 1][j];
            else
                f[i][j] =
                    max(f[i - 1][j], f[i][j - weights[i - 1]] + values[i - 1]);
        }
    }
    cout << f[n][v] << endl;
    return 0;
}