#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0,k = 0,cur = 0;
        while(i<n){
            if(nums[i]==val) {
                int j = i+1;
                while(j<n&&nums[j]==val){
                    j++;
                }
                if(j<n) {
                    nums[cur]=nums[j];
                    k++;
                }
                i = j+1;
            } else {
                nums[cur] = nums[i];
                k++;
                i++;
                }
            cur++;
        }
        return k;
    }
};

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution a;
    int out =  a.removeElement(nums,val);
    printf("out = %d\n",out);
    return 0;
}