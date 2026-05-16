#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> minStack;
        for (int i = 0; i < temperatures.size(); i++) {
            if (minStack.empty())
                minStack.push(i);
            else {
                while (!minStack.empty() &&
                       temperatures[i] > temperatures[minStack.top()]) {
                    ans[minStack.top()] = i - minStack.top();
                    minStack.pop();
                }
                minStack.push(i);
            }
        }
        return ans;
    }
};