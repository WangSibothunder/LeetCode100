#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> f(n, -1), has1(n), has0(n);
        for (int i = 0; i < n; i++) {
            int last = 0;
            int sum = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    sum += 1;
                    if (j > i) has1[i] = 1;
                } else {
                    sum -= 1;
                    if (j > i) has0[i] = 1;
                }
                if (sum == 0) {
                    if (j - i + 1 > last) {
                        last = j - i + 1;
                        f[i] = j;
                    }
                }
            }
        }
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int left_len = f[i] - i + 1;
            int left_rightend = f[i];
            int right = left_rightend + 3;
            int right_len = f[right] - (right)-1;
            printf("i=%d left_len=%d right_len=%d\n", i, left_len, right_len);
            printf("right=%d left_rightend=%d\n", right, left_rightend);
            if (left_rightend + 2 + 1 <= n - 1) {
                if (s[f[i] + 1] == '1' && has0[right + right_len - 1])
                    maxLen = max(maxLen, left_len + right_len + 2);
                else if (s[f[i] + 1] == '0' && has1[right + right_len - 1])
                    maxLen = max(maxLen, left_len + right_len + 2);
            }
        }
        return maxLen;
    }
};
int main() {
    string s = "1000011";
    Solution sol;
    int re = sol.longestBalanced(s);
    cout << re << endl;
    return 0;
}