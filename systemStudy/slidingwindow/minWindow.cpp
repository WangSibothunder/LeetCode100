#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> hashmap;
        unordered_map<char, int> windows;
        for (auto &ch : t)
        {
            hashmap[ch]++;
        }
        int i = 0;
        int s_size = s.size(), t_size = t.size();
        string ans = "";
        int n = t_size;
        if (s_size < t_size)
            return ans;
        for (int j = 0; j < s_size; j++)
        {
            if (hashmap.count(t[j]))
            {
                windows[t[j]]++;
                while (windows[t[j]] > hashmap[t[j]])
                {
                    i++;
                    windows[t[i]]--;
                }
            }
        }
    }
};