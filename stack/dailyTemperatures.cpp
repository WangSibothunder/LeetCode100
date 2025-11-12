#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> next_high;
        vector<int> ans(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!next_high.empty() && temperatures[i] > temperatures[next_high.top()])
            {
                int previousIndex = next_high.top();
                ans[previousIndex] = i - previousIndex;
                next_high.pop();
            }
            next_high.push(i);
        }
        return ans;
    }
};