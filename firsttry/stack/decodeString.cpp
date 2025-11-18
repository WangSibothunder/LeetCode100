#include <string>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    string getDigits(string &s, size_t &ptr)
    {
        string ret = "";
        while (isdigit(s[ptr]))
        {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }
    string getString(vector<string> &v)
    {
        string ret;
        for (const auto &s : v)
        {
            ret += s;
        }
        return ret;
    }

public:
    string decodeString(string s)
    {
        vector<string> stk;
        size_t ptr = 0;
        while (ptr < s.size())
        {
            char cur = s[ptr];
            if (isdigit(cur))
            {
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            }
            else if (isalpha(cur) || cur == '[')
            {
                stk.push_back(string(1, s[ptr++]));
            }
            else
            {
                ptr++;
                vector<string> substr;
                while (stk.back() != "[")
                {
                    substr.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(substr.begin(), substr.end());
                stk.pop_back();
                int repTime = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(substr);
                while (repTime--)
                    t += o;
                stk.push_back(t);
            }
        }
        return getString(stk);
    }
};