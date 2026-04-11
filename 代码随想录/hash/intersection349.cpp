#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> f(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++) {
            if (!f.count(nums2[i])) {
                nums2.erase(nums2.begin() + i);
                i--;
            } else
                f.erase(nums2[i]);
        }
        return nums2;
    }
};
int main() {
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    Solution sol;
    vector<int> re;
    re = sol.intersection(nums1, nums2);
    return 0;
}