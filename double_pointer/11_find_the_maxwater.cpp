#include<iostream>
using namespace std;
int main(){
    int num[9] = {1,8,6,2,5,4,8,3,7};
    int left_pointer = 0,right_pointer = 8;
    int max_area = -1,area = 0;
    while (left_pointer!=right_pointer){
        area = min(num[left_pointer],num[right_pointer])*(right_pointer-left_pointer);
        max_area = max(max_area,area);
        if(num[left_pointer]<num[right_pointer]) left_pointer++;
        else right_pointer--;
    }
    cout<<max_area;
    return 0;
}