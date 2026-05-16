#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        // 1.计算右边第一个比他小的
        int n = heights.size();
        stack<int> maxStack;
        vector<int> rightMin(n, n);
        for (int i = 0; i < n; i++) {
            while (!maxStack.empty() && heights[i] < heights[maxStack.top()]) {
                rightMin[maxStack.top()] = i;
                maxStack.pop();
            }
            maxStack.push(i);
        }
        maxStack = stack<int>();
        vector<int> leftMin(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!maxStack.empty() && heights[i] < heights[maxStack.top()]) {
                leftMin[maxStack.top()] = i;
                maxStack.pop();
            }
            maxStack.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            printf("height:%d,leftMin:%d,RightMin:%d", heights[i], leftMin[i],
                   rightMin[i]);
            int area = heights[i] * (rightMin[i] - leftMin[i] - 1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};