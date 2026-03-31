#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int max_len = -1;
        for (string ele : wordDict) {
            max_len = max(max_len, int(ele.size()));
        }
        unordered_set<string> word(wordDict.begin(), wordDict.end());
        vector<int> f(n + 1);  // f[i] present s[:i] is verified
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; (i - j) >= max_len; j--) {
                if (f[j] == 1 && word.count(s.substr(j, i - j))) f[i] = 1;
            }
        }
        return f[n];
    }
};
int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution sol;
    bool re = sol.wordBreak(s, wordDict);
    cout << re << endl;
    return 0;
}