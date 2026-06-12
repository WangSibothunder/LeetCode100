#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 进行广搜时需要关注不要出现重复入队操作
class Solution {
   public:
    int ans = 0;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void bfs(vector<vector<char>>& grid, int x, int y) {
        ans++;
        queue<pair<int, int>> queue;
        queue.push({x, y});
        grid[x][y] = '0';

        while (!queue.empty()) {
            int curx = queue.front().first;
            int cury = queue.front().second;
            queue.pop();
            for (int i = 0; i < 4; i++) {
                int tempx = curx + dir[i][0];
                int tempy = cury + dir[i][1];
                if (tempx >= 0 && tempx < grid.size() && tempy >= 0 &&
                    tempy < grid[0].size() && grid[tempx][tempy] == '1') {
                    queue.push({tempx, tempy});
                    grid[tempx][tempy] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == '1') {
                    bfs(grid, x, y);
                    // cout << ans << " ";
                }
            }
        }
        return ans;
    }
};