#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    bool flag_col = 0,flag_row = 0;
    for(int i = 0;i<matrix.size();i++){//便利行
        if(matrix[i][0]==0) flag_col = 1;
        for(int j = 0;j<matrix[0].size();j++){
            if(matrix[0][j]==0) flag_row = 1;
            if(matrix[i][j]==0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1;i<matrix.size();i++){
        for(int j = 1;j<matrix[0].size();j++){
            if(matrix[i][0]==0 || matrix[0][j]==0) {
                matrix[i][j] = 0;
            }
        }
    }
    if(flag_col) {
        for(int i = 0;i<matrix.size();i++) matrix[i][0] = 0;
    }
    if(flag_row) {
        for(int j = 0;j<matrix[0].size();j++) matrix[0][j] = 0;
    }
    return 0;
}