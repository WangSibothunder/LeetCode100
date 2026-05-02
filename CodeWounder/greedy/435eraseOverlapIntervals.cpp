#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] != b[1])
            return a[1] < b[1];
        else
            return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0, minRight = 0;
        for (auto& ele : intervals) {
            if (ele[0] >= minRight) {
                ans++;
                minRight = ele[1];
            }
        }
        return ans;
    }
};