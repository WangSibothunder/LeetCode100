#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Greater;
        vector<int> ans;
        int i;
        for (i = 0; i < k - 1; i++) {
            while (!Greater.empty() && nums[i] > nums[Greater.back()])
                Greater.pop_back();
            Greater.push_back(i);
        }
        for (i; i < nums.size(); i++) {
            while (!Greater.empty() && Greater.front() < i - k + 1)
                Greater.pop_front();
            while (!Greater.empty() && nums[i] > nums[Greater.back()])
                Greater.pop_back();
            Greater.push_back(i);
            ans.push_back(nums[Greater.front()]);
        }
        return ans;
    }
};