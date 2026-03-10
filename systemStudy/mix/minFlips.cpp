#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minFlips(string s) {
        int n = s.size();
        int ans = INT_MAX;
        int cnt = 0;
        for (int offset = 0; offset < n; offset++) {
            if (offset == 0) {
                for (int i = 0; i < n; i++) {
                    char ch = s[(i) % n];
                    if ((ch - '0') == i % 2) cnt++;  // 010101
                }
            } else {
                char ch = s[offset - 1];
                int cnttemp = cnt;
                if ((ch - '0') == 0) {  // 01010
                    cnttemp--;
                }
                cnt = (n - 1) - cnttemp + ((ch - '0') == (n - 1) % 2);

                // cnt = n-cnt;
            }
            ans = min(ans, min(cnt, n - cnt));
        }
        return ans;
    }
};
int main() {
    string s = "111000";
    Solution sol;
    int p = pow(2, 6);
    cout << p << endl;
    return 1;
    int ans = sol.minFlips(s);
    printf("ans = %d\n", ans);
    s = "123" + s;
    cout << s;
    return 0;
}