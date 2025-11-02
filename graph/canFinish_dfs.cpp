#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

    void dfs(int u)
    {
        visited[u] = 1; // 正在搜索
        for (int v : edges[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid)
                    return;
            }
            else if (visited[v] == 1)
            {
                // 回环到正在探索的
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (auto info : prerequisites)
            edges[info[0]].push_back(info[1]);
        for (int i = 0; i < numCourses && valid; i++)
            if (!visited[i])
                dfs(i);
        return valid;
    }
};

int main()
{
    Solution solution;

    // 测试用例1：有向无环图 - 可以完成所有课程
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test Case 1 (Should be true): " << (solution.canFinish(2, prerequisites1) ? "true" : "false") << endl;

    // 测试用例2：有向有环图 - 不能完成所有课程
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Test Case 2 (Should be false): " << (solution.canFinish(2, prerequisites2) ? "true" : "false") << endl;

    return 0;
}