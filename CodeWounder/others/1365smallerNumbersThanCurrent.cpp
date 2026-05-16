#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> toSort(nums), result(nums.size());
        sort(toSort.begin(), toSort.end());
        unordered_map<int, int> umap;
        for (int i = nums.size() - 1; i >= 0; i--) {
            umap[toSort[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            result[i] = umap[nums[i]];
        }
        return result;
    }
};