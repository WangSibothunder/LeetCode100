#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (obstacles[i] >= obstacles[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return f;
    }
};