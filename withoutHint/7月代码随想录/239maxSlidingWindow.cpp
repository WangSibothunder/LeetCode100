#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        for (int i = 0; i < k; i++) {
            while (!window.empty() && nums[i] > nums[window.back()])
                window.pop_back();
            window.push_back(i);
        }
        vector<int> ans;
        for (int i = k; i < nums.size(); i++) {
            ans.push_back(nums[window.front()]);
            while (!window.empty() && window.front() <= i - k)
                window.pop_front();
            while (!window.empty() && nums[i] > nums[window.back()])
                window.pop_back();
            window.push_back(i);
        }
        ans.push_back(nums[window.back()]);
        return ans;
    }
};