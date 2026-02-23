#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
    int col[9];
    bool inPath[9];
    int ans = 0;
    int n;
    unordered_set<int> left_valid_set, right_valid_set;
    void dfs(int i) {
        if (i == n) {
            ans++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!inPath[j] &&
                (left_valid_set.find(j + i) == left_valid_set.end()) &&
                right_valid_set.find(j - i) == right_valid_set.end()) {
                inPath[j] = true;
                left_valid_set.insert(j + i);
                right_valid_set.insert(j - i);
                dfs(i + 1);
                inPath[j] = false;
                left_valid_set.erase(left_valid_set.find(j + i));
                right_valid_set.erase(right_valid_set.find(j - i));
            }
        }
    }

   public:
    int totalNQueens(int n) {
        this->n = n;
        dfs(0);
        return ans;
    }
};