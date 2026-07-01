#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 二分查找无法处理不是n*n的矩阵
        int n = matrix.size();
        int m = matrix[0].size();
        int pY = n - 1, pX = 0;
        while (pY >= 0 && pX < m) {
            if (matrix[pY][pX] == target)
                return true;
            else if (matrix[pY][pX] > target)
                pY--;
            else
                pX++;
        }
        return false;
    }
};