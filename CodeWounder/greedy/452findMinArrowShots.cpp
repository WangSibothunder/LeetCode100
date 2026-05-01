#include <iostream>
#include <vector>
using namespace std;
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int shot = 1;
        sort(points.begin(), points.end(), cmp);
        int minRight = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= minRight) {
                minRight = min(minRight, points[i][1]);
                // continue;
            } else {
                shot++;
                minRight = points[i][1];
            }
        }
        return shot;
    }
};