#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, cost = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > cost) {
                ans = max(prices[i] - cost, ans);
            } else {
                cost = prices[i];
            }
        }
        return ans;
    }
};