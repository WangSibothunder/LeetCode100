#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> minStack;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!minStack.empty() &&
                   temperatures[i] > temperatures[minStack.top()]) {
                ans[minStack.top()] = i;
                minStack.pop();
            }
            minStack.push(i);
        }
        while (!minStack.empty()) {
            ans[minStack.top()] = 0;
            minStack.pop();
        }
        for (int i = 0; i < temperatures.size(); i++) {
            if (ans[i] != 0) ans[i] = ans[i] - i;
        }
        return ans;
    }
};