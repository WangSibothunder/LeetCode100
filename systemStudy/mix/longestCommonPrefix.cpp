#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (auto str : strs) {
            string temp = "";
            for (int i = 0; i < str.size() && i < ans.size(); i++) {
                if (ans[i] == str[i])
                    temp += ans[i];
                else
                    break;
            }
            ans = temp;
        }
        return ans;
    }
};