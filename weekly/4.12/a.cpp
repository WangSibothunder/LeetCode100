#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n);
        for (auto vec : matrix) {
            for (int i = 0; i < n; ++i) {
                ans[i] += vec[i];
            }
        }
        return ans;
    }
};
