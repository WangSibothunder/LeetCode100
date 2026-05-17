#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // bool bfs(vector<vector<int>>& matrix, int x, int y) {
    //     queue<pair<int, int>> que;
    //     que.push({x, y});
    //     while (!que.empty()) {
    //         int cur_x = que.front().first, cur_y = que.front().second;
    //         que.pop();

    //         for (auto dir : dirs) {
    //             int temp_x = cur_x + dir[0];
    //             int temp_y = cur_y + dir[1];
    //             if (temp_x < 0 || temp_x >= matrix.size() || temp_y < y ||
    //                 temp_y >= matrix.size())
    //                 continue;
    //             if (matrix[temp_x][temp_y] == 0) {
    //                 matrix[temp_x][temp_y] = matrix[cur_x][cur_y];
    //             } else if (matrix[temp_x][temp_y] > matrix[x][y]) {
    //                 return false;
    //             }
    //         }
    //     }
    // }
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != 0) {
                    int st_x = max(0, i - matrix[i][j]);
                    int ed_x = min(n - 1, i + matrix[i][j]);
                    int st_y = max(0, j - matrix[i][j]);
                    int ed_y = min(m - 1, j + matrix[i][j]);
                    int flag = 0;
                    cout << st_x << " " << ed_x << endl;
                    cout << st_y << " " << ed_y << endl;
                    for (int inner_i = st_x; inner_i <= ed_x; inner_i++) {
                        for (int inner_j = st_y; inner_j <= ed_y; inner_j++) {
                            if (inner_i == i - matrix[i][j] &&
                                (inner_j == j - matrix[i][j] ||
                                 inner_j == j + matrix[i][j]))
                                continue;
                            if (inner_i == i + matrix[i][j] &&
                                (inner_j == j - matrix[i][j] ||
                                 inner_j == j + matrix[i][j]))
                                continue;
                            if (matrix[inner_i][inner_j] > matrix[i][j]) {
                                flag = 1;
                                break;
                            }
                        }
                    }
                    if (flag == 0) ans++;
                }
            }
        }
        return ans;
    }
};
