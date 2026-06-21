#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool result = 0;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void backtracking(vector<vector<char>>& board, string word, int x, int y,
                      int layer) {
        if (layer == word.size() || result == 1) {
            result = 1;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int temp_x = x + dir[i][0];
            int temp_y = y + dir[i][1];
            if (temp_x < 0 || temp_x >= board.size()) continue;
            if (temp_y < 0 || temp_y >= board[0].size()) continue;
            // cout<<temp_x<<" "<<temp_y<<" "<<layer<<endl;
            if (board[temp_x][temp_y] == word[layer]) {
                board[temp_x][temp_y] = '-';
                backtracking(board, word, temp_x, temp_y, layer + 1);
                board[temp_x][temp_y] = word[layer];
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        // cout<<(board[3][2]==word[5]);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '-';
                    backtracking(board, word, i, j, 1);
                    board[i][j] = word[0];
                    if (result) return true;
                }
            }
        }
        return result;
    }
};