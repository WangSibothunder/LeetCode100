#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    static bool myCMP(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), myCMP);
        vector<vector<int>> ans;
        int idx = 0;
        while (idx < intervals.size()) {
            int st = intervals[idx][0], ed = intervals[idx][1];
            while (idx < intervals.size() && intervals[idx][0] <= ed) {
                ed = max(ed, intervals[idx][1]);
                idx++;
            }
            ans.push_back({st, ed});
        }
        return ans;
    }
};