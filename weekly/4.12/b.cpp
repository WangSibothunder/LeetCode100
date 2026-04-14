#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool examination(vector<int>& sides) {
        if (sides[0] + sides[1] > sides[2]) {
            if (sides[2] - sides[1] < sides[0] &&
                sides[2] - sides[0] < sides[1])
                return true;
        }
        return false;
    }
    double cos(vector<int>& sides, int idx) {
        double sqrsum = 0, sqra = 0, bc = 1;
        for (int i = 0; i < 3; i++) {
            int temp = sides[i] * sides[i];
            if (i == idx)
                sqra = temp;
            else {
                sqrsum += temp;
                bc *= sides[i];
            }
        }
        return (sqrsum - sqra) / (2 * bc);
    }
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        vector<double> ans;
        if (!examination(sides)) return ans;
        for (int i = 0; i < 3; i++) {
            double temp = cos(sides, i);

            ans.push_back(acos(temp) / M_PI * 180);
        }
        return ans;
    }
};
int main() {
    vector<int> sides = {2, 2, 3};
    Solution sol;
    vector<double> re = sol.internalAngles(sides);
    for (int i = 0; i < 3; i++) {
        cout << re[i] << endl;
    }

    return 0;
}