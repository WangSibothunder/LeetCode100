#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> partitionLabels(string s) {
        vector<int> showup(27);
        for (int i = 0; i < s.size(); i++) {
            showup[s[i] - 'a'] = i;
        }
        int idx = 0;
        vector<int> ans;
        while (idx < s.size()) {
            int i = idx, st = idx;
            for (; i <= showup[s[idx] - 'a']; i++) {
                if (showup[s[i] - 'a'] > showup[s[idx] - 'a']) idx = i;
            }
            // idx = showup[idx] + 1;
            ans.push_back(i - st);
            idx = i;
        }
        return ans;
    }
};