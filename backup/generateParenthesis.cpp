#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<string> result;
    string current;
    void backtrack(vector<string> &ans, string &cur, int open, int close, int n)
    {
        if (cur.size() == n * 2)
        {
            ans.push_back(cur);
            return;
        }
        if (open < n)
        {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open)
        {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        backtrack(result, current, 0, 0, n);
        return result;
    }
};