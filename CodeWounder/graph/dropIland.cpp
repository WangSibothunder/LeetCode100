#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int row, col;

void dfs(vector<vector<int>>& f, int x, int y) {
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    if (f[x][y] == 1) {
        f[x][y] = 2;
        for (auto dir : dirs) {
            if (f[x + dir[0]][y + dir[1]] == 1) dfs(f, x + dir[0], y + dir[1]);
        }
    }
}

int main() {
    scanf("%d %d", &row, &col);
    vector<vector<int>> f(row + 2, vector<int>(col + 2, 0));
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    for (int i = 1; i <= row; i++) {
        dfs(f, i, 1);
        dfs(f, i, col);
    }
    for (int j = 1; j <= col; j++) {
        dfs(f, 1, j);
        dfs(f, row, j);
    }
    for (int i = 1; i <= row; i++) {
        int j = 1;
        for (; j < col; j++) {
            if (f[i][j] == 2)
                printf("%d ", 1);
            else
                printf("%d ", 0);
        }
        if (f[i][j] == 2)
            printf("%d\n", 1);
        else
            printf("%d\n", 0);
    }
    return 0;
}