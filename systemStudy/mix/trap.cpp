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
                leftHeigh = temp.first;
                monotone.pop();
            }
            if (!monotone.empty()) {
                ans +=
                    (i - monotone.top().second - 1) * (height[i] - leftHeigh);
            }
            monotone.push(make_pair(height[i], i));
            // }
        }
        return ans;
    }
};
int main() {
    vector<int> height = {4, 2, 0, 3, 2, 5};
    Solution sol;
    int ans = sol.trap(height);
    printf("ans = %d\n", ans);
    return 0;
}