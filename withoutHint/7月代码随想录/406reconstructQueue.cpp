#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    static bool sortCMP(vector<int>& a, vector<int>& b) {
        if (a[1] != b[1]) return a[0] > b[0];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;

        // priority_queue<vector<int>, vector<vector<int>>, myCMP> pque;
        sort(people.begin(), people.end(), sortCMP);
        for (int i = 0; i < people.size(); i++) {
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};