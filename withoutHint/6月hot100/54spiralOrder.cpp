#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    // 每走完一圈
    // x和y的都需要减2，要走的步数是边长-1，停机条件是要走的步数变为0了。不过具体需要考虑是或还是与
    // 刚想了一下，循环条件应该是要走的步长都大于0，之后需要按照不等于0的那个纬度继续走直到走完（最后留下来一定是长条形状的）

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int chooseDir = 0;
        int step_x = n - 1, step_y = m - 1;
        int point_x = 0, point_y = 0;
        while (step_x >= 1 && step_y >= 1) {
            for (int i = 0; i < step_y; i++) {
                ans.push_back(matrix[point_x][point_y]);
                point_y++;
            }
            for (int j = 0; j < step_x; j++) {
                ans.push_back(matrix[point_x][point_y]);
                point_x++;
            }
            for (int i = 0; i < step_y; i++) {
                ans.push_back(matrix[point_x][point_y]);
                point_y--;
            }
            for (int j = 0; j < step_x; j++) {
                ans.push_back(matrix[point_x][point_y]);
                point_x--;
            }
            step_x -= 2;
            step_y -= 2;
            point_x += 1;
            point_y += 1;
        }
        // cout<<step_x<<" "<<step_y<<endl;
        // cout<<point_x<<" "<<point_y<<endl;
        if (step_x >= 0 && step_y >= 0) {
            if (step_x >= 1)
                for (int i = 0; i < step_x; i++) {
                    ans.push_back({matrix[point_x][point_y]});
                    point_x++;
                }
            else if (step_y >= 1)
                for (int i = 0; i < step_y; i++) {
                    ans.push_back({matrix[point_x][point_y]});
                    point_y++;
                }
            ans.push_back({matrix[point_x][point_y]});
        }

        return ans;
    }
};