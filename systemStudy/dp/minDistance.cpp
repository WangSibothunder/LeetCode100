#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector f (n+1,vector<int>(m+1,0));//相当于在word1和word2的前面都加上一个空格，后面需要记得删除
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(word1[i]==word2[j]) f[i+1][j+1] = f[i][j]+1;
                else f[i+1][j+1] = max(f[i][j+1],f[i+1][j]);
            }
        }
        int ans = n+m-f[n][m]*2;
        return ans;
    }
};