#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int size = numbers.size();
        vector<int> ans;
        int i = 0, j = size - 1;
        while ((numbers[i] + numbers[j]) != target)
        {
            if ((numbers[i] + numbers[j]) < target)
                i++;
            if ((numbers[i] + numbers[j]) > target)
                j--;
        }
        ans.push_back(i + 1);
        ans.push_back(j + 1);
        return ans;
    }
};