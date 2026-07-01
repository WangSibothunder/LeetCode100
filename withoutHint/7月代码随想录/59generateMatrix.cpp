#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        int x = 0, y = 0;
        int step = n - 1, cnt = 1;
        vector<vector<int>> grid(n, vector<int>(n));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (step > 0) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < step; j++) {
                    grid[x][y] = cnt++;
                    x += dirs[i].first;
                    y += dirs[i].second;
                }
            }
            step -= 2;
            x += 1;
            y += 1;
        }
        if (n % 2) grid[x][y] = cnt;
        return grid;
    }
};