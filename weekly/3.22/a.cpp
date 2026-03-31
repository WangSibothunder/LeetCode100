#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> nums2(n, 0);
        vector<vector<int>> op(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = nums1[i] - nums1[j];
                op[i][j] = abs(temp);
                op[j][i] = abs(-temp);
            }
        }
        int od = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == od) {
                cnt++;
                continue;
            }
            bool flag = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (op[i][j] % 2 == od) {
                    flag = 1;
                    cnt++;
                    break;
                }
            }
            if (!flag) break;
        }
        if (cnt == n) return true;
        od = 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == od) {
                cnt++;
                continue;
            }
            bool flag = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (op[i][j] % 2 == od) {
                    flag = 1;
                    cnt++;
                    break;
                }
            }
            if (!flag) break;
        }
        if (cnt == n)
            return true;
        else
            return false;
    }
};

int main() {
    vector<int> nums1 = {2, 3};
    Solution sol;
    bool re = sol.uniformArray(nums1);
    cout << re << endl;
    return 0;
}