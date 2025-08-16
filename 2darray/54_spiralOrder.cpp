#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> ans;
    int row_lenth = matrix[0].size();
    int col_lenth = matrix.size();
    int i = 0, j = 0;
    bool row_aim = 1, col_aim = 0; // 0 表示正方向

    // 第一行
    for(i = 0; i < row_lenth; i++){
        ans.push_back(matrix[0][i]);
        printf("i=%d, j=%d, matrix[%d][%d]=%d,row_lenth = %d,col_lenth = %d\n", i, 0, 0, i, matrix[0][i],row_lenth,col_lenth);
    }
    i--;
    j++;
    while (1) {

        if(col_aim == 0){ // 向下
            int j_temp = j;
            for(; j < (j_temp + col_lenth-1); j++){
                ans.push_back(matrix[j][i-1]);
                printf("i=%d, j=%d, matrix[%d][%d]=%d,row_lenth = %d,col_lenth = %d\n", i, j, j, i, matrix[j][i],row_lenth,col_lenth);
            }
            col_lenth--;
            col_aim = 1;
            j--;
            i--;
        } else { // 向上
            int j_temp = j;
            for(; j > (j_temp - col_lenth+1); j--){
                ans.push_back(matrix[j][i-1]);
                printf("i=%d, j=%d, matrix[%d][%d]=%d,row_lenth = %d,col_lenth = %d\n", i, j, j, i, matrix[j][i],row_lenth,col_lenth);
            }
            col_lenth--;
            col_aim = 0;
            i++;
            j++;
        }
        printf("遍历方向变化\n");
        if(row_aim == 1){ // 向左
            int i_temp = i;
            for(; i > (i_temp - row_lenth+1); i--){
                ans.push_back(matrix[j-1][i]);
                printf("i=%d, j=%d, matrix[%d][%d]=%d,row_lenth = %d,col_lenth = %d\n", i, j, j, i, matrix[j][i],row_lenth,col_lenth);
            }
            row_aim = 0;
            row_lenth--;
            j--;
            i++;
        } else { // 向右
            int i_temp = i;
            for(; i < (i_temp + row_lenth-1); i++){
                ans.push_back(matrix[j-1][i]);
                printf("i=%d, j=%d, matrix[%d][%d]=%d,row_lenth = %d,col_lenth = %d\n", i, j, j, i, matrix[j][i],row_lenth,col_lenth);
            }
            row_aim = 1;
            row_lenth--;
            j++;
            i--;
        }
        printf("遍历方向变化\n");
        if(row_lenth==0 || col_lenth==0) break;
    }
    return 0;
}
