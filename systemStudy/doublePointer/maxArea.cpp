#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int size = height.size();
        int ans = 0, left = 0, right = size - 1;
        while (left < right)
        {
            int temp = (right - left) * min(height[left], height[right]);
            ans = max(ans, temp);
            if (height[left] < height[right])
            {
                left++;
                while (height[left] == height[left - 1] && left < right)
                    left++;
            }
            else
            {
                right--;
                while (height[right] == height[right + 1] && left < right)
                    right--;
            }
        }
        return ans;
    }
};