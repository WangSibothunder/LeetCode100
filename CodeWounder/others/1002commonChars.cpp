#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> umapOld, umapNew;
        for (int i = 0; i < words[0].size(); i++) {
            umapOld[words[0][i]]++;
        }
        for (int w = 1; w < words.size(); w++) {
            string temp = words[w];
            for (int j = 0; j < (int)temp.size(); j++) {
                char c = temp[j];
                if (umapOld[c] > 0) {
                    umapNew[c]++;
                    umapOld[c]--;
                }
            }
            umapOld = umapNew;
            umapNew = unordered_map<char, int>();
        }
        vector<string> ans;
        for (auto key : umapOld) {
            for (int i = 0; i < key.second; i++) {
                ans.push_back(string(1, key.first));
            }
        }
        return ans;
    }
};