#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    int nr, nc;
    vector<vector<char>> Grid;
    void dfs(int r, int c)
    {
        Grid[r][c] = '0'; // 标记已经走过
        if (r - 1 >= 0 && Grid[r - 1][c] == '1')
            dfs(r - 1, c);
        if (r + 1 < nr && Grid[r + 1][c] == '1')
            dfs(r + 1, c);
        if (c - 1 >= 0 && Grid[r][c - 1] == '1')
            dfs(r, c - 1);
        if (c + 1 < nc && Grid[r][c + 1] == '1')
            dfs(r, c + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        Grid = grid;
        nr = Grid.size();
        if (nr == 0)
            return 0;
        nc = Grid[0].size(); // 记录边界
        int ans = 0;
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (Grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};