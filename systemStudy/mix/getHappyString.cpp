#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
    vector<string> ans;
    string vocab = "abc";
    void dfs(int n, string s, set<char> uset) {
        if (n == 0) {
            ans.push_back(s);
            return;
        }
        int s_size = s.size();
        for (auto ch : vocab) {
            if (uset.size() == 3) uset.erase(uset.begin());
            if (ch != uset.end()) {
                s += ch;
                uset.insert(ch);
                dfs(n - 1, s, uset);
                s = s.substr(0, s_size);
                uset.erase(ch);
            }
        }
    }

   public:
    string getHappyString(int n, int k) {
        set<char> uset;
        dfs(n, "", uset);
        if (ans.size() < k) return "";
        return ans[k];
    }
};

int main() {
    Solution sol;
    int n = 3, k = 9;
    string re = sol.getHappyString(n, k);
    cout << endl << re << endl;
    return 0;
}