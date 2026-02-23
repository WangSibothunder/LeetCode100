#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int i,int n,vector<int>& nums){
        if(i==n){
            ans.push_back(path);
            return;
        }
        for(auto ch:nums){
            path.push_back(ch);
            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
    }
};