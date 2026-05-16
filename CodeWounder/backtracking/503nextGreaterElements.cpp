#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> minStack;
        for (int j = 0; j < nums.size() * 2 - 1; j++) {
            // if (i < nums.size()) {
            int i = j;
            if (i >= nums.size()) i -= nums.size();
            while (!minStack.empty() && nums[i] > nums[minStack.top()]) {
                result[minStack.top()] = nums[i];
                minStack.pop();
            }
            minStack.push(i);
            // }
        }
        return result;
    }
};