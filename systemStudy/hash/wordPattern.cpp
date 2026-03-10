#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> umap;
        unordered_set<char> LUT;
        // if (s.size() != t.size()) return false;
        s += ' ';
        int i = 0, len = s.size(), cnt = 0;
        while (i < len) {
            int j = i;
            while (j < len && s[j] != ' ') j++;
            string temp = s.substr(i, j - i);
            i = j + 1;
            if (!umap.count(temp)) {
                if (LUT.count(pattern[cnt])) return false;  // mapping to others
                umap.insert({temp, pattern[cnt]});
                LUT.insert(pattern[cnt]);
            } else if (pattern[cnt] != umap[temp]) {
                return false;
            }
            cnt++;
        }
        if (cnt != pattern.size()) return false;
        return true;
    }
};

int main() {
    string pattern = "abba", s = "dog cat cat dog";
    Solution sol;
    bool re = sol.wordPattern(pattern, s);
    return 0;
}