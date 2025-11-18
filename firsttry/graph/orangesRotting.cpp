#include <queue>
#include <vector>
#include <utility>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q; // 腐烂橘子坐标序列
        int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int fresh_cnt = 0; // 新鲜橘子数量
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh_cnt++;
            }
        }
        if (q.size() == 0 && fresh_cnt)
            return -1; // 没有第一个橘子就不会腐烂
        int ans = 0;
        while (!q.empty())
        {
            int t = q.size(); // 存储同一时间被感染的橘子数量
            for (int i = 0; i < t; i++)
            {
                pair<int, int> temp = q.front();
                q.pop();
                for (auto &dir : direction)
                {
                    int x = temp.first + dir[0];
                    int y = temp.second + dir[1];
                    // 注意：应当用 n 来检查列的上界
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        fresh_cnt--;
                        q.push({x, y});
                    }
                }
            }
            if (!q.empty())
                ans++;
        }
        if (fresh_cnt)
            return -1;
        return ans;
    }
};