#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> f(s.size() + 1);
        f[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                if (wordDict[j].size() <= i) {
                    if (wordDict[j] ==
                        s.substr(i - wordDict[j].size(), wordDict[j].size())) {
                        if (f[i - wordDict[j].size()]) f[i] = 1;
                    }
                }
            }
        }
        // for (auto ele : f) {
        //     cout << ele << " ";
        // }
        return f[s.size()];
    }
};