#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> combine;
    void backtrack(vector<int> &combine, int target, vector<int> &choices, int start)
    {
        if (target == 0)
        {
            ans.push_back(combine);
            return;
        }
        for (int i = start; i < choices.size(); i++)
        {
            if (target - choices[i] < 0)
                break;
            combine.push_back(choices[i]);
            backtrack(combine, target - choices[i], choices, i);
            combine.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtrack(combine, target, candidates, 0);
        return ans;
    }
};