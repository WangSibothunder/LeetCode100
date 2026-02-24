#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector f(n+1,vector<int>(m+1,INT_MAX));
        f[0][1] = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                f[i+1][j+1] = min(f[i+1][j],f[i][j+1]) +grid[i][j];
            }
        }
        return f[n][m];
    }
};