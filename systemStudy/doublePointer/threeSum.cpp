#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int size = nums.size();
        for (int i = 0; i < size - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) // 跳过重复的 i
                continue;
            int j = i + 1;
            int k = size - 1;
            while (j < k) 
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    // 跳过重复的 j 和 k
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
                else if (sum < 0)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution a;
    vector<vector<int>> ans = a.threeSum(nums);
    return 0;
}