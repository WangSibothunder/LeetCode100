#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    vector<vector<string>> ans;
    unordered_map<string, int> uset;
    int kind = 0;
    void dfs(string str, int len, string newstr) {
        if (len == 0) {
            uset.insert({newstr, kind});
            return;
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ' ') {
                newstr += str[i];
                str[i] = ' ';
                dfs(str, len - 1, newstr);
                str[i] = newstr[newstr.size() - 1];
                newstr = newstr.substr(0, newstr.size() - 1);
            }
        }
        return;
    }

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> subset;
        for (auto str : strs) {
            if (!uset.count(str)) {
                dfs(str, str.size(), "");
                kind++;
                ans.resize(kind + 1);
            }
            ans[uset[str]].push_back(str);
        }
        return ans;
    }
};
int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(strs);
    return 0;
}