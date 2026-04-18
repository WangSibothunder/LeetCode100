#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> umap;
        for (auto& num1 : nums1) {
            for (auto& num2 : nums2) {
                int temp = num1 + num2;
                if (umap.count(temp)) {
                    umap[temp]++;
                } else
                    umap.insert({temp, 1});
            }
        }
        int ans = 0;
        for (auto& num3 : nums3) {
            for (auto& num4 : nums4) {
                int temp = num3 + num4;
                temp = 0 - temp;
                if (umap.count(temp)) {
                    ans++;
                    umap[temp]--;
                    if (umap[temp] == 0) umap.erase(temp);
                }
            }
        }
        return ans;
    }
};