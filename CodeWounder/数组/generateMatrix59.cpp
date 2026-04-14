#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        int direction[4][4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int x = 0, y = 0;
        int loop = n / 2;
        int cnt = 0;
        for (int loop_ = 0; loop_ < loop; loop_++) {
            for (int dir = 0; dir < 4; dir++) {
                for (int step = 0; step < n - 1; step++) {
                    matrix[x][y] = ++cnt;
                    y += direction[dir][0];
                    x += direction[dir][1];
                }
            }
            x++;
            y++;
            n -= 2;
        }
        if (n % 2) matrix[x][y] = cnt++;
        return matrix;
    }
};
int main() {
    int n = 3;
    Solution sol;
    vector<vector<int>> gen = sol.generateMatrix(n);
    return 0;
}