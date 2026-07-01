#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Bigger {
   public:
    bool operator()(int& a, int& b) { return a < b; }
};
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, Bigger> pqueue;
        for (int i = 0; i < nums.size(); i++) {
            pqueue.push(nums[i]);
        }
        int lastpop = INT_MIN;
        for (int i = 0; i < k; i++) {
            if (pqueue.top() == lastpop) {
                pqueue.pop();
            } else {
                lastpop = pqueue.top();
                pqueue.pop();
            }
        }
        return lastpop;
    }
};