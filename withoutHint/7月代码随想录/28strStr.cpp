#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> next;
    int pos = 0;
    void init(string needle) {
        for (int i = 1; i < needle.size(); i++) {
            if (needle[i] == needle[pos]) {
                next[i] = pos;
                pos++;
            } else {
                while (pos != 0 && needle[i] != needle[pos]) {
                    pos = next[pos - 1] + 1;
                }
                if (needle[i] == needle[pos]) {
                    next[i] = pos;
                    pos++;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        next = vector<int>(needle.size(), -1);
        init(needle);
        // for (int i = 0; i < needle.size(); i++) printf("%d ", next[i]);
        // cout << endl;
        int pos = 0;
        int j = 0;
        for (j; j < haystack.size(); j++) {
            // cout << needle.substr(0, pos + 1) << " ";
            if (pos == needle.size()) return j - pos;
            if (haystack[j] == needle[pos]) {
                pos++;
            } else {
                if (pos == 0)
                    continue;
                else
                    while (pos != 0 && haystack[j] != needle[pos]) {
                        pos = next[pos - 1] + 1;
                    }
                if (haystack[j] == needle[pos]) pos++;
            }
        }
        if (pos == needle.size()) return j - pos;

        return -1;
    }
};