#include <iostream>
#include <vector>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    bool inPath[6];

    int n;
    void dfs(int i, vector<int>& nums) {
        if (i == n) {
            ans.push_back(path);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!inPath[j]) {
                inPath[j] = true;
                path.push_back(nums[j]);
                dfs(i + 1, nums);
                inPath[j] = false;
                path.pop_back();
            }
        }
    }

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        dfs(0, nums);
        return ans;
    }
};