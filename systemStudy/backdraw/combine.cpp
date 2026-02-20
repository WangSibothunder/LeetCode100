#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    vector<int> k_pair;
    void dfs(int i,int n,int k){//i表示深度
        if(i==k) {
            ans.push_back(k_pair);
            return;
        }
        int j;
        if(i==0) j = 0;
        else j = k_pair.back();
        j+=1;
        for(j;j<=n;j++){
            k_pair.push_back(j);
            dfs(i+1,n,k);
            k_pair.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(0,n,k);
        return ans;
    }
};