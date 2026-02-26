#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0,j = 0,cur = 0;
        vector<int> Sort(m+n,0);
        while (i<m&&j<n)
        {
            if(nums1[i]>nums2[j]) {
                Sort[cur++] = nums2[j++];
            }
            else Sort[cur++] = nums1[i++];
        }
        while (i<m)
        {
            Sort[cur++] = nums1[i++];
        }
        while (j<n)
        {
            Sort[cur++] = nums2[j++];
        }
        // nums1.erase(nums1.begin()+m+n-1,nums1.end());
    }
};