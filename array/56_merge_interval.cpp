#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());//排序可保证起点一致

    vector<vector<int>> ans;
    for(int i = 0; i<intervals.size();i++){
        int L = intervals[i][0], R = intervals[i][1];
        if(ans.size()==0||ans.back()[1]<L){//一个是空需要加入，一个是发现当前虚恋是一个新的起点
            ans.push_back(intervals[i]);
        } else if(R>ans.back()[1]){
            ans.back()[1] = R;
        }
    }
    return 0;
}