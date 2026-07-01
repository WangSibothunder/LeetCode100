#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, INT_MAX);
        f[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size() && i >= coins[j]; j++) {
                if (f[i - coins[j]] != INT_MAX)
                    f[i] = min(f[i - coins[j]] + 1, f[i]);
            }
        }
        // for (auto ele : f) {
        //     if (ele == INT_MAX)
        //         cout << "... ";
        //     else
        //         cout << ele << " ";
        // }
        return f[amount] == INT_MAX ? -1 : f[amount];
    }
};