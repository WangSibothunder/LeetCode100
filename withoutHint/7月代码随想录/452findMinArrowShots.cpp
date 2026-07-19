#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    static bool myCMP(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), myCMP);
        int times = 0;
        int i = 0;
        while (i < points.size()) {
            int st = points[i][0], ed = points[i][1];
            while (i < points.size() && points[i][0] <= ed) {
                ed = min(ed, points[i][1]);
                i++;
            }
            times++;
        }
        return times;
    }
};