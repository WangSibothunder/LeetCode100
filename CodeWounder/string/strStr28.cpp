#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> nxt;
    void get_nxt(string needle) {
        nxt = vector<int>(needle.size());
        nxt[0] = -1;
        int j = -1;
        for (int i = 1; i < needle.size(); i++) {
            while (j != -1 && needle[i] != needle[j + 1]) {
                j = nxt[j];
            }
            if (needle[i] == needle[j + 1]) j++;
            nxt[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        get_nxt(needle);
        int j = -1;
        int i;
        for (i = 0; i < haystack.size(); i++) {
            while (j != -1 && haystack[i] != needle[j + 1]) {
                j = nxt[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j + 1 == needle.size()) break;
        }
        if (j + 1 == needle.size()) return i - (j);
        return -1;
    }
};
int main() {
    string haystack = "mississippi", needle = "issip";
    Solution sol;
    int ans = sol.strStr(haystack, needle);
    cout << ans << endl;
    return 0;
}