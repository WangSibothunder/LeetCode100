#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    string s = "cbaebabacd", p = "abc";
    vector<int> ans;
    int p_len = p.size(), s_len = s.size();
    if(s_len < p_len) return 0;
    unordered_map<char,int> s_nums, p_nums;
    for(int i = 0; i < p_len; i++){
        p_nums[p[i]]++;
        s_nums[s[i]]++;
    }
    if(s_nums == p_nums) ans.push_back(0);
    for(int i = p_len; i < s_len; i++){
        s_nums[s[i]]++;
        s_nums[s[i-p_len]]--;
        if(s_nums[s[i-p_len]] == 0) s_nums.erase(s[i-p_len]);
        if(s_nums == p_nums) ans.push_back(i-p_len+1);
    }
    for(int idx : ans) cout << idx << " ";
    cout << endl;
    return 0;
}