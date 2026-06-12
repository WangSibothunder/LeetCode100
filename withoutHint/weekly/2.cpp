#include <algorithm>  // 必须包含 sort 头文件（你漏了）
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 加上 const，保证只读
    static bool cmp(const vector<int>& itemA, const vector<int>& itemB) {
        return itemA[0] > itemB[0];
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        // 正确写法：Solution::cmp 显式指定静态函数
        sort(items.begin(), items.end(), Solution::cmp);

        for (int i = 0; i < items.size(); i++) {
            cout << items[i][0] << " ";
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> items = {{2, 4}, {3, 2}, {4, 1}, {6, 4}, {12, 4}};
    Solution sol;
    int re = sol.maximumSaleItems(items, 0);
    return 0;
}