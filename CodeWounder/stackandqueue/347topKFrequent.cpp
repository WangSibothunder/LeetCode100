#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    class myconpare {
       public:
        bool operator()(pair<int, int>& l, pair<int, int>& r) {
            return l.second > r.second;  // left is greater than right:min heap
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for (auto num : nums) {
            if (!umap.count(num))
                umap[num] = 1;
            else
                umap[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, myconpare> pque;
        for (auto ele : umap) {
            pque.push(ele);
            if (pque.size() > k) pque.pop();
        }
        vector<int> ans;
        while (!pque.empty()) {
            ans.push_back(pque.top().first);
            pque.pop();
        }
        return ans;
    }
};