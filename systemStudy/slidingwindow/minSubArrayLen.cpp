#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        int sum = 0, ans = n + 1;
        for (int j = 0; j < n; j++)
        {
            sum += nums[j];
            while (sum - nums[i] >= target)
            {
                sum -= nums[i];
                i++;
            }
            if (sum >= target)
            {
                // printf("i=%d,j=%d,sum=%d\n", i, j, sum);
                ans = min(ans, j - i + 1);
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};
int main()
{
    Solution a;
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 15;
    a.minSubArrayLen(target, nums);
    return 0;
}