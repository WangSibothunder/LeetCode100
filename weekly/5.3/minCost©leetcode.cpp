#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> shunxu(nums), nixu(nums);
        shunxu[0] = 0;
        shunxu[1] = 1;
        nixu[n - 1] = 0;
        nixu[n - 2] = 1;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] < nums[i] - nums[i - 1])
                shunxu[i + 1] = shunxu[i] + 1;
            else
                shunxu[i + 1] = shunxu[i] + nums[i + 1] - nums[i];
        }
        for (int i = n - 2; i >= 1; i--) {
            if (nums[i] - nums[i - 1] <= nums[i + 1] - nums[i])
                nixu[i - 1] = nixu[i] + 1;
            else
                nixu[i - 1] = nixu[i - 1] + nums[i] - nums[i - 1];
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] < queries[i][1]) {
                ans[i] = shunxu[queries[i][1]] - shunxu[queries[i][0]];
            } else {
                ans[i] = nixu[queries[i][0]] - nixu[queries[i][1]];
            }
        }
        return ans;
    }
};