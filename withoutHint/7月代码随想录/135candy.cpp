#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int candy(vector<int>& ratings) {
        vector<int> left(ratings.size(), 1), right(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            // 左往右
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            // 右往左
            if (ratings[ratings.size() - 1 - i] > ratings[ratings.size() - i]) {
                right[ratings.size() - 1 - i] = right[ratings.size() - i] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < ratings.size(); i++) {
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};