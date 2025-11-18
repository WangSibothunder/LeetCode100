#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int &num : nums)
        {
            if (st.count(num - 1))
                continue;
            int y = num + 1;
            while (st.count(y))
                y++;
            ans = max(ans, y - num);
            if (ans * 2 >= st.size())
                break;
        }
        return ans;
    }
};