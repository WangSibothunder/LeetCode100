#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
                    // 0. 1. 2. 3. 4. 5. 6. 7. 8. 9. 10.11
    vector<int> height{4, 2, 0, 3, 2, 5};
    int n =0;
    int left = 0, right = 0,right_down;
    bool right_first_down = 0 , right_bigger_left = 0 , right_upper_check = 0;
    while(right <= height.size()-1){
        if(height[left]>height[left+1]){//局部峰值
            for(right = left+1;right<=height.size()-1;right++){
                if(height[right]>=height[left]) {
                    right_bigger_left=1;
                    break;//右侧比左侧高
                }
                if(right<=height.size()-2&&height[right+1]>height[right]) right_upper_check = 1;
                if(right<=height.size()-2&&height[right]>height[right+1]&&right_first_down==0&&right_upper_check){
                    right_down = right;
                    right_first_down = 1;
                }
            }
            if(right_bigger_left){//右侧比左侧高情况
                for(int j = left+1;j<=right-1;j++){
                    n+=height[left]-height[j];
                }
                printf("从left%d到right%d，n为%d\n",left,right,n);
                left = right;
                
            }   else if(right_first_down){
                for(int j = left+1;j<=right_down-1;j++){
                    n+=height[right_down]-height[j];
                }
                printf("从left%d到right_down%d，n为%d\n",left,right_down,n);

                left=right_down;
                //左侧比右侧高，没有扫描到；
            } 

            right_bigger_left=0;
            right_first_down=0;
            right_upper_check= 0;
        } else if(left>=height.size()-2){
            break;
        }
        else left++;
    }
    cout<<n<<endl;
    return 0;
}