#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;  // val,idx
        for (int i = 0; i < nums.size(); i++) {
            if (umap.count(target - nums[i]))
                return {i, umap[target - nums[i]]};
            umap.insert({nums[i], i});
        }
        return {-1, -1};
    }
};