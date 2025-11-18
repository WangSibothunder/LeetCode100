#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int size = s.size();
        vector<int> dp(size, 0);
        int ans = 0;
        for (int i = 1; i < size; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    if (i >= 2)
                        dp[i] = dp[i - 2] + 2;
                    else
                        dp[i] = 2;
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + (i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0 + 2;
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
