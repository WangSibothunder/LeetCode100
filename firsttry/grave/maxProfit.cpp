#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        vector<int> stack;
        prices.push_back(-1);
        for (int i = 0; i < prices.size(); i++)
        {
            while (!stack.empty() && prices[i] < stack.back())
            {
                ans = max(ans, stack.back() - stack.front());
                stack.pop_back();
            }
            stack.push_back(prices[i]);
        }
        return ans;
    }
};