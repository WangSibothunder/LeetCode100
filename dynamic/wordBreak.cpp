#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words;
        for (auto word : wordDict)
        {
            words.insert(word);
        }
        int sSize = s.size();
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i < sSize; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && words.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sSize];
    }
};