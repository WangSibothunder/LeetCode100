#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> index;
        vector<int> non_negation_v;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                index.push_back(i);  // index存档的是非负下标
                non_negation_v.push_back(nums[i]);
            }
        }
        // 对index做循环位移
        int n_index = index.size();
        for (int i = 0; i < n_index; i++) {
            int shift_index = index[(i - k % n_index + n_index) % n_index];
            nums[shift_index] = non_negation_v[i];
        }
        return nums;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, -2, 3, -4};
    int k = 3;
    vector<int> result = sol.rotateElements(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}