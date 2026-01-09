#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1; // Ë«±ß±ÕÇø¼ä
        while (left <= right)
        {
            int mid = (left + right + 1) >> 1;
            // printf("mid = %d\n", mid);
            if (target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    Solution a;
    int ans = a.searchInsert(nums, target);
    printf("%d", ans);
    return 0;
}