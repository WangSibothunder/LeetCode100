#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    bool is_palindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
    vector<string> path;
    vector<vector<string>> ans;

public:
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        auto dfs = [&](auto &&self, int i, int start)
        {
            if (i == n)
            {
                ans.push_back(path);
                return;
            }
            if (i < n - 1)
                self(self, i + 1, start); // 改为通过 self 递归
            if (is_palindrome(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                self(self, i + 1, i + 1); // 改为通过 self 递归
                path.pop_back();
            }
        };
        dfs(dfs, 0, 0); // 初始调用时传入自身
        return ans;
    }
};