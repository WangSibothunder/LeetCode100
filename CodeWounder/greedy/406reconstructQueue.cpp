#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    bool cmp(const vector<int>& a, const vector<int>& b) const {
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = people.size();
        map<int, vector<vector<int>>> umap;
        vector<vector<int>> ans(people.size());
        for (auto& ele : people) {
            int h = ele[0], k = ele[1];
            umap[k].push_back(ele);
        }
        queue<vector<int>> candidate;
        for (int i = 0; i < size; i++) {
            if (umap[i].size() != 0) {
                sort(umap[i].begin(), umap[i].end(), cmp);
                for (auto& ele : umap[i]) candidate.push(ele);
            }
            ans[i] = candidate.front();
            candidate.pop();
        }
        return ans;
    }
};