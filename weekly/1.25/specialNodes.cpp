#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        unordered_map<int, vector<int>> AdjacencyList;
        unordered_map<int, int> visited_iter;
        int dx, dy, dz;
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            AdjacencyList[edges[i][0]].push_back(edges[i][1]);
            AdjacencyList[edges[i][1]].push_back(edges[i][0]);
            visited_iter[edges[i][0]] = -1;
            visited_iter[edges[i][1]] = -1;
        }
        int ans = 0;
        for (auto node : visited_iter) {
            unordered_map<int, int> visited{visited_iter};
            queue<int> q;
            int u = node.first;
            q.push(u);
            visited[u] = 0;
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                printf("当前节点为：%d\n", front);
                for (int i = 0; i < AdjacencyList.at(front).size(); i++) {
                    if (visited[AdjacencyList[front][i]] == -1) {
                        visited[AdjacencyList[front][i]] = visited[front] + 1;
                        q.push(AdjacencyList[front][i]);
                    }
                    if (AdjacencyList[front][i] == x)
                        dx = visited[AdjacencyList[front][i]];
                    else if (AdjacencyList[front][i] == y)
                        dy = visited[AdjacencyList[front][i]];
                    else if (AdjacencyList[front][i] == z)
                        dz = visited[AdjacencyList[front][i]];
                }
            }
            int nums[3] = {dx, dy, dz};
            sort(nums, nums + 3, greater<int>());
            if (nums[0] * nums[0] + nums[1] * nums[1] == nums[2] * nums[2])
                ans++;
        }
        return ans;
    }
};
