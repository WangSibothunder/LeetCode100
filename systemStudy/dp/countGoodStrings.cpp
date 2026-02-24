#include<iostream>
using namespace std;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> f(high+1,0);
        const int MOD = 1'000'000'000+7;
        int ans = 0;
        f[0] = 1;
        for(int i = 1;i<=high;i++){
            if(i>=zero) f[i]+=f[i-zero];
            if(i>=one) f[i]+=f[i-one];
            f[i] = f[i]%MOD;
            if(i>=low) ans = (ans+f[i])%MOD;
        }
        return ans;
    }
};