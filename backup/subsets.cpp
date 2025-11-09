#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    vector<int> t;
    vector<vector<int>> ans;

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++)
        {
            t.clear();
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    t.push_back(nums[j]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};