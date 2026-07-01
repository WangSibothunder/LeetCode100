#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class myCamp {
   public:
    bool operator()(pair<int, int>& times_a, pair<int, int>& times_b) {
        return times_a < times_b;
    }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> times;
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCamp> pqueue;
        for (int i = 0; i < nums.size(); i++) {
            times[nums[i]]++;
        }
        for (auto& ele : times) {
            pqueue.push({ele.first, ele.second});
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(pqueue.top().first);
            pqueue.pop();
        }
        return ans;
    }
};
int main() {
    unordered_map<int, int> times = {{1, 2}};
    for (auto& ele : times) {
        cout << ele.first << endl;
        cout << ele.second << endl;
    }
    return 0;
}