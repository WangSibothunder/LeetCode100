#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& f, vector<vector<bool>>& group, int x, int y) {
    if (group[x][y] == 1 || f[x][y] == 0) return;
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    group[x][y] = 1;
    for (auto dir : dirs) {
        int nxtX = x + dir[0], nxtY = y + dir[1];
        if (f[nxtX][nxtY] >= f[x][y]) {
            dfs(f, group, nxtX, nxtY);
        }
    }
    // f[x][y] = 0;
}

int row, col;
int main() {
    scanf("%d %d", &row, &col);
    vector<vector<int>> f(row + 2, vector<int>(col + 2, 0));
    vector<vector<bool>> group1(row + 2, vector<bool>(col + 2, 0)),
        group2(row + 2, vector<bool>(col + 2, 0));
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    for (int i = 1; i <= row; i++) {
        dfs(f, group1, i, 1);
        dfs(f, group2, i, col);
    }
    for (int j = 1; j <= col; j++) {
        dfs(f, group1, 1, j);
        dfs(f, group2, row, j);
    }
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (group1[i][j] && group2[i][j]) printf("%d %d\n", i - 1, j - 1);
        }
    }
    return 0;
}