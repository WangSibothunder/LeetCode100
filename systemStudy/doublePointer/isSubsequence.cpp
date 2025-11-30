#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int s_size = s.size();
        int t_size = t.size();
        if (s_size > t_size)
            return false;
        if (s == t || s_size == 0)
            return true;
        int i = 0, j = 0;
        for (; j < t_size; j++)
        {
            if (s[i] == t[j])
            {
                i++;
                if (i == s_size)
                    return true;
            }
        }
        return false;
    }
};