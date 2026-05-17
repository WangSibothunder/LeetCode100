#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), count = 0;
        vector<int> visited(n);
        count++;
        visited[0] = 1;
        queue<int> que;
        que.push(0);
        while (!que.empty()) {
            int temp = que.front();
            que.pop();
            for (auto key : rooms[temp]) {
                if (visited[key])
                    continue;
                else {
                    visited[key] = 1;
                    count--;
                    que.push(key);
                }
            }
        }
        if (count == n) return true;
        return false;
    }
};