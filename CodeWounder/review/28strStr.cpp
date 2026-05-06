#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> initNext(string needle) {
        int n = needle.size();
        vector<int> next(n, -1);
        int j = -1;
        for (int i = 1; i < n; i++) {
            while (j >= 0 && needle[j + 1] != needle[i])
            // j：当前判断的前缀的下标-1，如果j==-1，说明needle【0】也不满足要求；
            {
                j = next
                    [j];  // 当前前缀和needle【i】不一样，说明当前前缀下标-1和needle【i-1】是一样的
            }
            if (needle[j + 1] == needle[i]) j++;
            next[i] = j;
        }
        return next;
    }
    int strStr(string haystack, string needle) {
        vector<int> next = initNext(needle);
        int i, j = -1;  // j表示需要判断的下标-1
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[j + 1]) {
                j++;
            } else {
                while (j >= 0 && haystack[i] != needle[j + 1]) {
                    j = next[j];
                }
                if (haystack[i] == needle[j + 1]) j++;
            }
            if (j == needle.size() - 1) return i - needle.size() + 1;
        }
        return -1;
    }
};