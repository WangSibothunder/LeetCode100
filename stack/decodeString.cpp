#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution
{
    stack<pair<int, string>> stk;
    string ans = "";
    string mulstring(int nums, string str)
    {
        string out;
        for (int i = 0; i < nums; i++)
        {
            out += str;
        }
        return out;
    }

public:
    string decodeString(string s)
    {
        int num = 0;
        bool inb = 0;
        string temp = "";
        s += "[]";
        for (char ch : s)
        {
            if (ch >= '0' && ch <= '9')
            {
                num = num * 10 + ch - '0';
            }
            if (ch == '[')
            {
                stk.push(make_pair(num, temp));

                num = 0;
                temp = "";
            }
            if (ch >= 'a' && ch <= 'z')
            {
                temp += ch;
            }
            if (ch == ']')
            {
                string before_str = stk.top().second;
                int before_nums = stk.top().first;
                printf("temp:");
                cout << temp << endl;
                printf("before_nums=%d\n", before_nums);
                before_str = before_str + mulstring(before_nums, temp);
                printf("before_str:");
                cout << before_str << endl;
                stk.pop();
                temp = "";
                if (stk.empty())
                    ans += before_str;
                else
                {
                    string before_before_str = stk.top().second;
                    int nums = stk.top().first;
                    before_before_str = before_before_str + before_str;
                    stk.pop();
                    stk.push(make_pair(nums, before_before_str));
                }
            }
        }
        return ans;
    }
};
int main()
{
    string s = "3[a2[c]]";
    Solution a;
    string out = a.decodeString(s);
    cout << out;
    return 0;
}