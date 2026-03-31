#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, (INT_MAX / 2) - 1);
        f[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (i - coin >= 0) f[i] = min(f[i - coin] + 1, f[i]);
            }
        }
        return f[amount] < (INT_MAX / 2) - 1 ? f[amount] : -1;
    }
};
int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int re = sol.coinChange(coins, amount);
    cout << re << endl;
    return 0;
}
