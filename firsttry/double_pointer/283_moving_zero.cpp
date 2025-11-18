#include<iostream>
#include<vector>
using namespace std;
// 1 0 2 0 3 0 4
int main(){
    int num[100];
    int i = 0;
    char c;
    vector<int> none_zero;
    while ((c=getchar())!='\n'){
        if(c!=' ') {num[i]=c-'0';
        i++;}
    }
    //i指向最后一个元素的坐标
    // cout<<"i = "<<i<<'\n';
    int tempstart,tempend;
    int start = 0,end = i;
    for(start = 0;start<=end;start++){
        if (num[start]!=0) {
            none_zero.push_back(num[start]);//记录非零元素坐标
        }
    }
    for (int head = 0;head<=end;head++){
        if(none_zero.size()!=0){
            tempstart = none_zero[0];
            
            none_zero.erase(none_zero.begin());
            num[head] = tempstart;
        } else {
            num[head]=0;
        }
    }

    for(int j = 0;j<=i;j++){
        printf("%d ",num[j]);
    }
    return 0;
}