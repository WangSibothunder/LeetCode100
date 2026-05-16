#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> matrix;
    vector<vector<string>> ans;
    vector<string> transToString(vector<vector<int>>& matrix) {
        vector<string> matrixTrans;
        for (auto& line : matrix) {
            string temp = "";
            for (auto ele : line) {
                if (ele == 0)
                    temp += ".";
                else
                    temp += "Q";
            }
            matrixTrans.push_back(temp);
        }
        return matrixTrans;
    }
    bool checkLeg(int x, int y) {
        // 水平不需要判断是否合法，因为一行只放一个
        for (int i = 0; i < x; i++) {
            if (matrix[i][y]) return false;  // 判断垂直方向
            if (x - (i + 1) >= 0) {
                if (y - i - 1 >= 0 && matrix[x - i - 1][y - i - 1])
                    return false;  // 左上方
                if (y + i + 1 < matrix[0].size() &&
                    matrix[x - i - 1][y + i + 1])
                    return false;  // 右上方
            }
        }
        return true;
    }
    void backtracking(int layer, int n) {
        if (layer == n) {
            ans.push_back(transToString(matrix));
        }
        // printf("layer:%d,n:%d\n",layer,n);
        vector<int> line;
        line.resize(n);
        for (int i = 0; i < n; i++) {
            line[i] = 1;
            // printf("layer:%d,i:%d\n", layer, i);
            if (checkLeg(layer, i)) {
                // cout << "pass" << endl;
                // printf("line: ");
                // for (auto& ele : line) printf("%d ", ele);
                // cout << endl;
                matrix.push_back(line);
                // printf("matrix: \n");
                // for (auto& row : matrix) {
                //     for (auto& ele : row) printf("%d ", ele);
                //     cout << endl;
                // }
                // cout << endl;
                backtracking(layer + 1, n);
                matrix.pop_back();
            }
            line[i] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        backtracking(0, n);
        return ans;
    }
};
int main() {
    int n = 4;
    Solution sol;
    vector<vector<string>> ans = sol.solveNQueens(n);
    return 0;
}