#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
private:
    vector<string> generateBoard(vector<int> &queue, int n)
    {
        vector<string> board;
        for (int i = 0; i < n; i++)
        {
            string row = string(n, '.');
            row[queue[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }

    void bactrack(vector<vector<string>> &ans, vector<int> &queues, int n, int row, unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2)
    {
        if (row == n)
        {
            vector<string> board = generateBoard(queues, n);
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) // 这里在为row找可行坐标
        {
            if (columns.find(i) != columns.end())
                continue;
            int diagonal1 = row - i;
            if (diagonals1.find(diagonal1) != diagonals1.end())
                continue;
            int diagonal2 = row + i;
            if (diagonals2.find(diagonal2) != diagonals2.end())
                continue;
            queues[row] = i;
            columns.insert(i);
            diagonals1.insert(diagonal1);
            diagonals2.insert(diagonal2);
            bactrack(ans, queues, n, row + 1, columns, diagonals1, diagonals2);
            queues[row] = -1;
            columns.erase(i);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        auto columns = unordered_set<int>();
        auto diagonals1 = unordered_set<int>();
        auto diagonals2 = unordered_set<int>();
        bactrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
        return solutions;
    }
};