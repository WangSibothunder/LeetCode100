#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<string> ans;
    string path;
    void backtrack(int n, int cost) {
        if (cost < 0) return;
        if (n == 0) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        if (path.size() > 0 && path.back() == '1') {
            path.push_back('0');
            backtrack(n - 1, cost - (n - 1));
            path.pop_back();
        } else {
            path.push_back('0');
            backtrack(n - 1, cost);
            path.pop_back();
            path.push_back('1');
            backtrack(n - 1, cost - (n - 1));
            path.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        backtrack(n, k);
        return ans;
    }
};
int main() {
    string path = "010";
    reverse(path.begin(), path.end());
    cout << path;
    return 0;
}