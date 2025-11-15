#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for(auto &num:nums){
            if(num==candidate) ++count;
            else if (--count<0){
                candidate = num;
                count =0;
            }
        }
        return count;
    }
};