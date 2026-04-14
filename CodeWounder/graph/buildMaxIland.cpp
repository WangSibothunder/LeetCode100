#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int row, col;
int mark = 2;
unordered_map<int, int> areaLUT;
vector<vector<int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void maxArea(vector<vector<int>>& f) {
    queue<pair<int, int>> path;
    // int maxArea = 0;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (f[i][j] == 1) {
                int tempArea = 0;
                path.push({i, j});
                f[i][j] = mark;
                while (!path.empty()) {
                    pair<int, int> cur = path.front();
                    path.pop();
                    tempArea++;
                    for (auto dir : dirs) {
                        int nxtX = cur.first + dir[0];
                        int nxtY = cur.second + dir[1];
                        if (f[nxtX][nxtY] == 1) {
                            path.push({nxtX, nxtY});
                            f[nxtX][nxtY] = mark;
                        }
                    }
                }
                areaLUT.insert({mark, tempArea});
                mark++;
                // maxArea = max(maxArea, tempArea);
            }
        }
    }
    // return maxArea;
}

int main() {
    scanf("%d %d", &row, &col);
    vector<vector<int>> f(row + 2, vector<int>(col + 2, 0));
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            scanf("%d", &f[i][j]);
        }
    }
    maxArea(f);
    int maxArea = areaLUT[2];
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (f[i][j] == 0) {
                int tempArea = 1;
                for (auto dir : dirs) {
                    int nxtX = i + dir[0];
                    int nxtY = j + dir[1];
                    if (f[nxtX][nxtY] != 0) {
                        tempArea += areaLUT[f[nxtX][nxtY]];
                    }
                }
                maxArea = max(maxArea, tempArea);
            }
        }
    }
    printf("%d\n", maxArea);
    return 0;
}