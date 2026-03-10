#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umap;
        unordered_set<char> LUT;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < t.size(); i++) {
            char ch = t[i];
            if (!umap.count(ch)) {
                if (LUT.count(s[i])) return false;  // mapping to others
                umap.insert({ch, s[i]});
                LUT.insert(s[i]);
            } else if (s[i] != umap[ch]) {
                return false;
            }
        }
        return true;
    }
};