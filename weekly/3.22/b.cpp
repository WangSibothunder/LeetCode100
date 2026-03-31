#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Solution {
   public:
    bool uniformArray(vector<int>& nums1) {
        int oddCnt = 0, evenCnt = 0;
        int minOdd = numeric_limits<int>::max();
        int minEven = numeric_limits<int>::max();

        for (int x : nums1) {
            if (x & 1) {
                oddCnt++;
                if (x < minOdd) minOdd = x;
            } else {
                evenCnt++;
                if (x < minEven) minEven = x;
            }
        }

        // 全为偶数: 已经满足
        if (oddCnt == 0) return true;
        // 全为奇数: 已经满足
        if (evenCnt == 0) return true;

        // 目标全奇时, 每个偶数都需要存在更小的奇数可做一次操作
        return minEven > minOdd;
    }
};

int main() {
    vector<int> nums1 = {1, 4, 7};
    Solution sol;
    bool re = sol.uniformArray(nums1);
    cout << re << endl;
    return 0;
}
