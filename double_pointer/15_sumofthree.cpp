#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums= {-1,0,1,2,-1,-4};
    vector<vector<int>> checkpoint;
    bool flag = 0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        printf("%d ",nums[i]);
    }
    int first=0,second=nums.size()-1,third=0;
    for(first = 0;first<=second;first++){
        while((nums[first]+nums[second])>(-nums[second-1]) && (nums[first]+nums[second])<(-nums[first+1])&&second>first){//最大最小只和如果没办法满足就不能搜索
                // flag = 0;
                for(third = 0; third<=second; third++){
                    if(nums[third]==-(nums[first]+nums[second])) {
                        // flag= 1;
                        checkpoint.push_back({nums[first],nums[second],nums[third]});
                        break;}
                }
                second--;

        }
    }
    for(int i = 0;i<checkpoint.size();i++){
            printf("组合%d:[%d,%d,%d]\n",i,checkpoint[i][0],checkpoint[i][1],checkpoint[i][2]);
    }
    return 0;
}