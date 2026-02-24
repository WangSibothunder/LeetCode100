#include<iostream>
#include<vector>
using namespace std;
class Solution {
    
public:
    int countTexts(string pressedKeys) {
        long long ans = 1;
        const int MOD = 1'000'000'007;
        int n = pressedKeys.size();
        vector<long long> f(n+4,0),g(n+4,0);
        f[0] = g[0] = 1;
        f[1] = g[1] = 1;
        f[2] = g[2] = 2;
        f[3] = g[3] = 4;
        for(int i = 4;i<=n;i++){
            f[i] = (f[i-1]+f[i-2]+f[i-3])%MOD;
            g[i] = (g[i-1]+g[i-2]+g[i-3]+g[i-4])%MOD;
        }
        int j = 0;
        for(int i = 0;i<n;i++){
            char ch = pressedKeys[i];
            if(i==n-1||ch!=pressedKeys[i+1]){
                if(ch=='7'||ch=='9') ans = (ans*g[i-j+1])%MOD;
                else ans = (ans*f[i-j+1])%MOD;
                j = i+1;
            }
        }
        return ans;

    }
};