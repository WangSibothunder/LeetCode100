#include <deque>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> singleQueue;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k - 1) {
                while (singleQueue.front() < i - (k - 1)) {
                    singleQueue.pop_front();
                }
            }
            while (!singleQueue.empty() && nums[singleQueue.back()] < nums[i]) {
                singleQueue.pop_back();
            }
            singleQueue.push_back(i);
            if (i > k - 1) {
                cout << i << endl;
                ans.push_back(nums[singleQueue.front()]);
            }
        }
        return ans;
    }
};