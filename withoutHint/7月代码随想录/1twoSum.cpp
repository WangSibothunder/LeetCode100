#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[target - nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (umap[nums[i]] && umap[nums[i]] != i) return {umap[nums[i]], i};
        }
        return;
    }
};