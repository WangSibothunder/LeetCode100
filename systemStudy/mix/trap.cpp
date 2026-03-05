#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    int trap(vector<int>& height) {
        stack<pair<int, int>> monotone;  //[height][index]
        int n = height.size();
        int ans = 0;
        monotone.push(make_pair(height[0], 0));
        for (int i = 1; i < n; i++) {
            // else {
            int leftHeigh = height[i - 1];
            pair<int, int> temp = monotone.top();
            while (!monotone.empty() && monotone.top().first <= height[i]) {
                // this case means updating
                temp = monotone.top();
                ans += (i - temp.second - 1) * (temp.first - leftHeigh);
                monotone.pop();
            }
            if (!monotone.empty()) monotone.push(make_pair(height[i], i));
            // }
        }
        return ans;
    }
};