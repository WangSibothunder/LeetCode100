#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxTime = INT_MIN;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que, tempque;
        // que.push({x, y});
        int good = 0;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == 1)
                    good++;
                else if (grid[x][y] == 2)
                    que.push({x, y});
            }
        }
        int timer = 0;
        if (good == 0) return 0;
        while (!que.empty()) {
            int curx = que.front().first;
            int cury = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int tempx = curx + dir[i][0];
                int tempy = cury + dir[i][1];
                if (tempx >= 0 && tempx < grid.size() && tempy >= 0 &&
                    tempy < grid[0].size()) {
                    if (grid[tempx][tempy] == 1) {
                        grid[tempx][tempy] = 2;
                        tempque.push({tempx, tempy});
                        good--;
                    }
                }
            }
            if (que.empty()) {
                que = tempque;
                timer++;
                tempque = queue<pair<int, int>>();
                // for (int x = 0; x < grid.size(); x++) {
                //     for (int y = 0; y < grid[0].size(); y++) {
                //         cout << grid[x][y] << " ";
                //     }
                //     cout << endl;
                // }
            }
        }
        if (good) return -1;
        return timer - 1;
    }
};