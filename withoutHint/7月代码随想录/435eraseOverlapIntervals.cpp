#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    static bool myCMP(vector<int>& a, vector<int>& b) {
        if (a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), myCMP);
        int times = 0;
        int i = 0;
        while (i < intervals.size()) {
            int ed = intervals[i][1];
            i++;
            while (i < intervals.size() && intervals[i][0] < ed) {
                times++;
                i++;
            }
        }
        return times;
    }
};