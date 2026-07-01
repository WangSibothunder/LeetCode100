#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> points;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) points.push_back({i, j});
            }
        }
        for (int t = 0; t < points.size(); t++) {
            for (int j = 0; j < m; j++) matrix[points[t][0]][j] = 0;
            for (int i = 0; i < n; i++) matrix[i][points[t][1]] = 0;
        }
    }
};