#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int row, col;

int maxArea(vector<vector<int>>& f) {
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    queue<pair<int, int>> path;
    int sumArea = 0;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (f[i][j] == 1) {
                int tempArea = 0;
                path.push({i, j});
                f[i][j] = 0;
                bool flag = 1;
                while (!path.empty()) {
                    pair<int, int> cur = path.front();
                    path.pop();
                    tempArea++;
                    for (auto dir : dirs) {
                        int nxtX = cur.first + dir[0];
                        int nxtY = cur.second + dir[1];
                        if (nxtX == 0 || nxtY == 0 || nxtX == row + 1 ||
                            nxtY == col + 1)
                            flag = 0;
                        if (f[nxtX][nxtY] == 1) {
                            path.push({nxtX, nxtY});
                            f[nxtX][nxtY] = 0;
                        }
                    }
                }
                if (flag) sumArea += tempArea;
            }
        }
    }
    return sumArea;
}

int main() {
    scanf("%d %d", &row, &col);
    vector<vector<int>> f(row + 2, vector<int>(col + 2, 0));
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    int re = maxArea(f);
    printf("%d\n", re);
    return 0;
}