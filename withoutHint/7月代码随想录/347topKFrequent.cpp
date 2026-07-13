#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class myCMP {
   public:
    static bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> utimes;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCMP> pqueue;
        for (int i = 0; i < nums.size(); i++) utimes[nums[i]]++;
        for (auto& ele : utimes) {
            pqueue.push(ele);
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pqueue.top().first);
            pqueue.pop();
        }
        return ans;
    }
};