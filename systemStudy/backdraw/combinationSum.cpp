#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    int candidates_lenth;
    void dfs(int i,vector<int>& candidates, int target){
        if(target==0){
            ans.push_back(path);
            return;
        }
        int temp;
        int j = i;
        for(j;j<candidates_lenth;j++){
            temp = target-candidates[j];
            if(temp<0) continue;
            path.push_back(candidates[j]);
            dfs(j,candidates,temp);
            path.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        candidates_lenth = candidates.size();
        dfs(0,candidates,target);
        return ans;
    }
};