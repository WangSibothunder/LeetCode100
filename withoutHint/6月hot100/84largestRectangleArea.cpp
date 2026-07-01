#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> maxStack_r, maxStack_l;
        vector<int> r_limit(heights.size()), l_limit(heights.size());
        int maxArea = 0;
        // 从左往右，记录右边的边界位置
        for (int i = 0; i < heights.size(); i++) {
            while (!maxStack_r.empty() &&
                   heights[i] < heights[maxStack_r.top()]) {
                int temp = maxStack_r.top();
                r_limit[temp] = i;
                maxStack_r.pop();
            }
            maxStack_r.push(i);
        }
        while (!maxStack_r.empty()) {
            int temp = maxStack_r.top();
            r_limit[temp] = heights.size();
            maxStack_r.pop();
        }
        // 从右往左，记录左边界
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!maxStack_l.empty() &&
                   heights[i] < heights[maxStack_l.top()]) {
                int temp = maxStack_l.top();
                l_limit[temp] = i;
                maxStack_l.pop();
            }
            maxStack_l.push(i);
        }
        while (!maxStack_l.empty()) {
            int temp = maxStack_l.top();
            l_limit[temp] = -1;
            maxStack_l.pop();
        }
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, (r_limit[i] - l_limit[i] - 1) * heights[i]);
        }
        return maxArea;
    }
};