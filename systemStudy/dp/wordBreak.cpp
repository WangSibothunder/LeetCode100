#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> cache(wordDict.begin(), wordDict.end());
        }
};