#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long temp = 1;
        vector<int> idx;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num == 0) {
                idx.push_back(i);
                if (idx.size() > 1)
                    return vector<int>(nums.size());
                else if (idx.size() == 1)
                    continue;
            }

            temp *= nums[i];
        }
        vector<int> ans(nums.size());
        if (idx.size() == 1) {
            ans[idx[0]] = temp;
            return ans;
        }

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = temp / nums[i];
        }
        return ans;
    }
};