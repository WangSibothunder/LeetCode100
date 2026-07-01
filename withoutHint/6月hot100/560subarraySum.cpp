#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        int ans = 0, s = 0;
        for (auto& num : nums) {
            umap[s]++;
            s += num;
            if (umap.count(s - k)) ans += umap[s - k];
        }
        return ans;
    }
};