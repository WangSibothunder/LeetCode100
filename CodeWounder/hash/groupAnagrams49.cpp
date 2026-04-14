#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_set<unordered_map<char, int>> uset;
        vector<vector<string>> ans;
        for (auto str : strs) {
            unordered_map<char, int> umap;
            for (auto ch : str) {
                if (umap.count(ch))
                    umap[ch]++;
                else {
                    umap.insert({ch, 1});
                }
            }
        }
    }
};