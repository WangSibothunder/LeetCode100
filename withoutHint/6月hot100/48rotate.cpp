#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();                      // rows
        int m = matrix[0].size();                   // cols
        for (int iter = 0; iter < n / 2; iter++) {  // flip row
            swap(matrix[iter], matrix[n - iter - 1]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};