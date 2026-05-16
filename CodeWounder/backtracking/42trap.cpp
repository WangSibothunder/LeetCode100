#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    int trap(vector<int>& height) {
        int area = 0;
        stack<int> minStack;
        for (int i = 0; i < height.size(); i++) {
            while (minStack.size() > 1 && height[i] >= height[minStack.top()]) {
                int curIndex = minStack.top();
                minStack.pop();
                int leftIndex = minStack.top();
                int high = min(height[i], height[leftIndex]) - height[curIndex];
                int lenth = i - leftIndex - 1;
                area += high * lenth;
                printf("cur: %d,left: %d,right: %d,high: %d,len: %d\n",
                       height[curIndex], height[leftIndex], height[i], high,
                       lenth);
            }
            if (minStack.empty() || height[i] < height[minStack.top()])
                minStack.push(i);

            else {
                while (!minStack.empty() && height[i] >= height[minStack.top()])
                    minStack.pop();
                minStack.push(i);
            }
        }
        return area;
    }
};