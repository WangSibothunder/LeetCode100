#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> partitionLabels(string s) {
        vector<int> counter(26);
        for (int i = 0; i < s.size(); i++) {
            int alpha = s[i] - 'a';
            counter[alpha] = i;
        }
        vector<int> ans;
        int i = 0;
        int alpha = s[i] - 'a';
        while (i < s.size()) {
            int alpha = s[i] - 'a';
            int longest = counter[alpha];
            for (int j = i + 1; j < longest; j++) {
                longest = max(longest, counter[s[j] - 'a']);
            }
            ans.push_back(longest - i + 1);
            i = longest + 1;
        }
        return ans;
    }
};