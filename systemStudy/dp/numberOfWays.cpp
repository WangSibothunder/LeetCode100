#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int numberOfWays(int n, int x) {
        int MOD = 1'000'000'000 +7;
        int ans = 0;
        int len = pow(n,1.0/x)+1;
        vector f(len+1,vector<int>(n+1,0));
        f[0][0] = 1;
        for(int i = 0;i<len;i++){
            for(int j = 0;j<=n;j++){
                int num = pow(i,x);
                if(j<num) f[i+1][j] = f[i][j];
                else f[i+1][j] = f[i][j]+f[i][j-num];
            }
        }
        return f[len][n] ;

    }
};