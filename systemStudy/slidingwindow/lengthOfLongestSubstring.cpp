#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int i = 0;
        int ans = 1;
        unordered_map<char, int> hushmap;
        for (int j = 0; j < n; j++)
        {
            hushmap[s[j]]++;
            while (hushmap[s[j]] > 1)
            {
                hushmap[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
int main()
{
    Solution a;
    string s = "abcabcbb";
    int ans = a.lengthOfLongestSubstring(s);
    printf("%d", ans);
    return 0;
}