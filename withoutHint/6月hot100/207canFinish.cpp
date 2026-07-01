#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> gridIn(numCourses);
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            gridIn[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> course;
        int finish = 0;
        for (int i = 0; i < numCourses; i++) {
            if (gridIn[i] == 0) {
                course.push(i);
                // cout << i << " ";
                finish++;
            }
        }
        // cout << endl;
        while (!course.empty()) {
            for (int i = 0; i < graph[course.front()].size(); i++) {
                gridIn[graph[course.front()][i]]--;
                // cout << gridIn[graph[course.front()][i]] << " ";
                if (gridIn[graph[course.front()][i]] == 0) {
                    course.push(graph[course.front()][i]);
                    finish++;
                }
            }
            // cout << endl;
            course.pop();
        }
        if (finish != numCourses) return false;
        return true;
    }
};