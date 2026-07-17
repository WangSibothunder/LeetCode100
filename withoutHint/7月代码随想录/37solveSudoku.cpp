#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool finish = false;
    bool isValid(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || y < 0 || x >= 9 || y >= 9) return false;
        char uchar = board[x][y];
        for (int i = 0; i < 9; i++)
            if ((i != y && board[x][i] == uchar) ||
                (i != x && board[i][y] == uchar))
                return false;
        int tx = x / 3, ty = y / 3;
        for (int i = tx * 3; i < tx * 3 + 3; i++) {
            for (int j = ty * 3; j < ty * 3 + 3; j++) {
                if (!(i == x && j == y) && board[i][j] == uchar) return false;
            }
        }
        return true;
    }
    void backtracking(vector<vector<char>>& board, int x, int y) {
        if (finish) return;
        if (board[x][y] != '.') {
            y++;
            if (y >= 9) {
                y = 0;
                x++;
            }
            if (x == 9) {
                finish = 1;
                return;
            }
            backtracking(board, x, y);
            return;
        }
        for (int i = 1; i <= 9; i++) {
            board[x][y] = i + '0';
            if (isValid(board, x, y)) {
                backtracking(board, x, y);
                if (finish) return;
            }
            board[x][y] = '.';
        }
    }
    void solveSudoku(vector<vector<char>>& board) { backtracking(board, 0, 0); }
};