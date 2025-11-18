#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution
{
private:
    void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len)
    {
        if (first == len)
        {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; i++)
        {
            swap(output[i], output[first]);
            backtrack(res, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        int lenth = nums.size();
        backtrack(res, nums, 0, lenth);
        return res;
    }
};