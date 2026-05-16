#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        int hash[1001]{};
        unordered_map<int, int> umap;
        for (auto& ele : arr) {
            umap[ele]++;
        }
        for (auto key : umap) {
            if (hash[key.second] == 0)
                hash[key.second] = 1;
            else
                return false;
        }
        return true;
    }
};