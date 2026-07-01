#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool static cmp(vector<int> a,vector<int>b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int i = 0;
        while(i<intervals.size()){
            vector<int> temp(2);
            temp = intervals[i];
            int nxt = i;
            while(nxt<intervals.size()&&intervals[nxt][0]<=temp[1]) {
                temp[1] = max(temp[1],intervals[nxt][1]);
                nxt++;
            }
            // temp.push_back(intervals[nxt-1][1]);
            i = nxt;
            ans.push_back(temp);
        }
        return ans;
    }
};
