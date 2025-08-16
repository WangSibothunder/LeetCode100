#include<iostream>
#include<unordered_map>
using namespace std;

bool isSubMap(const unordered_map<char, int>& a, const unordered_map<char, int>& b) {
    for (const auto& kv : b) {
        if (a.count(kv.first) == 0 || a.at(kv.first) < kv.second) {
            return false;
        }
    }
    return true;
}

int main(){
    string s = "ADOBECODEBANC", t = "ABC";
    string ans ="",sub_s="";
    unordered_map<char,int> aim_first_index;//第一次出现时的坐标
    unordered_map<char,int> t_bottle,sub_string_bottle;//字符，键值，如果追踪的字符二次出现了，则更新到第一次出现的节点
//========================
//      滑动窗口初始化
//========================
    int min_aim_first_index ,pos;
    for(int i = 0;i<t.size();i++){
        if(t_bottle.count(t[i])==0){
            pos = s.find(t[i]);
            aim_first_index[t[i]] = pos;
            min_aim_first_index = min(pos,min_aim_first_index);
            t_bottle[t[i]] = 1;
        } else t_bottle[t[i]]++;
    }
    for(int i = 0; i<t.size();i++){
        sub_s +=s[i];
        if(sub_string_bottle.count(s[i])==0){
            sub_string_bottle[s[i]] = 1;
            if(s[i])
        } else sub_string_bottle[s[i]]++;
    }
//========================
//      轮寻，从第一个追踪开始
//========================
    for(int i = t.size();i<s.size();i++){
        if (t_bottle == sub_string_bottle){
            ans = sub_s;
        } else if(isSubMap(sub_string_bottle,t_bottle)){

        }
    }
    return 0;
}