#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调队列
        deque<int> que;
        vector<int> ans;
        int i = 0;
        for (; i < k - 1; i++) {
            while (!que.empty() && nums[i] > nums[que.back()]) {
                que.pop_back();
            }
            que.push_back(i);
        }
        for (; i < nums.size(); i++) {
            while (!que.empty() && nums[i] > nums[que.back()]) {
                que.pop_back();
            }
            que.push_back(i);
            while (que.front() <= i - k) {
                que.pop_front();
            }
            ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};