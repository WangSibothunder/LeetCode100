#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> umap;
        for (auto ch : s) {
            if (umap.count(ch))
                umap[ch]++;
            else
                umap.insert({ch, 1});
        }
        for (auto ch : t) {
            if (!umap.count(ch))
                return false;
            else
                umap[ch]--;
            if (umap[ch] < 0) return false;
        }
        return true;
    }
};