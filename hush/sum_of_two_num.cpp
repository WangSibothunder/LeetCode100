#include<iostream>
using namespace std;
int main(){
    int num[100];
    int i=0,target;
    char c;
    while ((c=getchar())!='\n'){
        if(c!=' ') {num[i]=c-'0';
        i++;}
    }
    // printf("the len of num: %d",i);55
    cin>>target;
    int start = 0, end = i;
    for (start = 0; start<i; start++){
        for(int j = start+1;j<=end;j++){
            // printf("curent start:%d curent num1:%d,curent num2:%d\n",start,num[start],num[j]);
            if(num[start]+num[j] == target){
                cout<<start<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}