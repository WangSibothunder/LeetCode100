#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1; //
        int ans = right + 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int left = 0, right = 4; // 0 1 2 3 4
    printf("%d", (left + right) >> 1);
    return 0;
}