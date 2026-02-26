#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector f(n+1,vector<int> (amount+1,0));
        f[0][0] = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=amount;j++){
                if(j<coins[i]) f[i+1][j] = f[i][j];
                else f[i+1][j] = f[i][j]+f[i+1][j-coins[i]];
            }
        }
        return f[n][amount];
    }
};