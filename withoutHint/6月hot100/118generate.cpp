#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // vector<int> path(1, 1);
        // ans.push_back(path);
        for (int i = 1; i <= numRows; i++) {
            vector<int> path_new(i, 1);
            for (int j = 1; j < i - 1; j++) {
                path_new[j] = ans.back()[j] + ans.back()[j - 1];
            }
            ans.push_back(path_new);
        }
        return ans;
    }
};