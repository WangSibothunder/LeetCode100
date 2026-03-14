#include <unordered_map>

#include "tree.h"
class Solution {
    unordered_map<int, vector<int>> umap;
    int ans = 0;
    string s;
    int dfs(int root) {
        int left_len = 0;
        int right_len = 0;
        for (auto child : umap[root]) {
            if (s[child] != s[root]) {
                int temp = dfs(child);
                if (temp > left_len) {
                    right_len = left_len;
                    left_len = temp;
                } else if (temp > right_len)
                    right_len = temp;
            }
        }
        ans = max(ans, left_len + right_len + 1);
        return max(left_len, right_len) + 1;
    }

   public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        this->s = s;
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                if (umap.count(parent[i]))
                    umap[parent[i]].push_back(i);
                else
                    umap.insert({parent[i], {i}});
            }
        }
        dfs(0);
        return ans;
    }
};
int main() {
    vector<int> parent = {-1, 0, 1};
    string s = "aab";
    Solution sol;
    sol.longestPath(parent, s);
    return 0;
}