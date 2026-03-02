#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector f(n+1,vector<int>(m+1,0));
        for (int i = 0; i < n; i++)
        {
            f[i+1][0] = f[i][0]+s1[i];
        }
        for (int j = 0; j < m; j++)
        {
            f[0][j+1] = f[0][j]+s2[j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(s1[i]==s2[j]) f[i+1][j+1] = f[i][j];
                else f[i+1][j+1] = min(f[i][j+1]+s1[i],f[i+1][j]+s2[j]);
            }
            
        }
        return f[n][m];
    }
};