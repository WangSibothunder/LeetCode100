#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int bfs(vector<vector<int>>& grid, int x, int y) {
        int cnt = 0;
        queue<pair<int, int>> que;
        que.push({x, y});
        grid[x][y] = -1;
        while (!que.empty()) {
            int curX = que.front().first, curY = que.front().second;
            que.pop();
            for (auto dir : dirs) {
                int tempX = curX + dir[0];
                int tempY = curY + dir[1];
                if (tempX < 0 || tempX >= grid.size() || tempY < 0 ||
                    tempY >= grid[0].size())
                    cnt++;
                else if (grid[tempX][tempY] == 0)
                    cnt++;
                else if (grid[tempX][tempY] == 1) {
                    que.push({tempX, tempY});
                    grid[tempX][tempY] = -1;
                }
            }
        }
        return cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) cnt += bfs(grid, i, j);
            }
        }
        return cnt;
    }
};