#include <iostream>
#include <vector>
using namespace std;
class Solution {
    bool ans = false;
    int n;
    // char path[15];
    int i_max, j_max;
    vector<vector<char>> board;
    bool visited[6][6];
    void dfs(int curLenth, string word, int i, int j) {
        if (curLenth == n) {
            ans = true;
            return;
        }
        for (int i_offset : {-1, 1}) {
            int new_i = i + i_offset;
            if (new_i < 0 || new_i >= i_max) continue;
            if (board[j][new_i] != word[curLenth] || visited[j][new_i] == true)
                continue;
            else {
                visited[j][new_i] = true;
                dfs(curLenth + 1, word, new_i, j);
                visited[j][new_i] = false;
            }
        }
        for (int j_offset : {-1, 1}) {
            int new_j = j + j_offset;
            if (new_j < 0 || new_j >= j_max) continue;
            if (board[new_j][i] != word[curLenth] || visited[new_j][i] == true)
                continue;
            else {
                visited[new_j][i] = true;
                dfs(curLenth + 1, word, i, new_j);
                visited[new_j][i] = false;
            }
        }
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        n = word.size();
        this->board = board;
        this->i_max = board[0].size();
        this->j_max = board.size();
        for (int i = 0; i < i_max; i++) {
            for (int j = 0; j < j_max; j++) {
                if (board[j][i] != word[0]) continue;
                visited[j][i] = true;
                dfs(1, word, i, j);
                visited[j][i] = false;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };
    string word = "EEE";

    Solution s;
    bool found = s.exist(board, word);
    cout << (found ? "true" : "false") << endl;
    return 0;
}
