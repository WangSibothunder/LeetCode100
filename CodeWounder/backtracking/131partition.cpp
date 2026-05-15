#include <iostream>
#include <vector>
using namespace std;
class Solution {
    vector<string> path;
    vector<vector<string>> ans;
    bool isPara(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    void backtracking(int start, int end,
                      string s) { /* @param start:字符串分割起点 @param
                                     end：分割终点 @param s:字符串*/
        // if (isPara(start, end, s.substr(start, end - start)))
        //     path.push_back(s.substr(start, end - start));
        if (start > end) {
            ans.push_back(path);
            return;
        }
        for (int cut = start; cut <= end; cut++) {
            string cur = s.substr(start, (cut - start + 1));
            string nxt = s.substr(cut + 1, end - cut);
            // cout << "cur:" << cur << " nxt:" << nxt << endl;
            if (isPara(cur)) {
                path.push_back(cur);
                // 代码注释掉是因为：cut在end的时候描述了这种情况
                //  if (nxt != "" && isPara(nxt)) {
                //      path.push_back(nxt);
                //      ans.push_back(path);
                //      path.pop_back();
                //  }
                backtracking(cut + 1, end, s);
                path.pop_back();
            }
        }
    }

   public:
    vector<vector<string>> partition(string s) {
        backtracking(0, s.size() - 1, s);
        return ans;
    }
};