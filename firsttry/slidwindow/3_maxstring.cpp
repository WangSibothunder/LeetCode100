#include<iostream>
#include<vector>
using namespace std;
int main(){
    // string s = "abcabcbb";
    string s ="bbbbb";
    // string s = "pwwkew";
    s = s+"_";
    int left = 0,right = 1;
    int max_lenth = -1;
    vector<char> char_list={s[left]};
    while(right<=s.size()-1){
        if(count(char_list.begin(),char_list.end(),s[right])==0){//未查询到
            char_list.push_back(s[right]);
            
        } else{
            max_lenth = max(max_lenth,right-left);
            // printf("当前left：%d；right：%d,最大长度:%d\n",left, right,max_lenth);
            left = right;
            char_list = {s[left]};
        }
        right++;
    }

    return 0;
}