#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int monotoneIncreasingDigits(int n) {
        string ans = "";
        int pre = n % 10;
        n /= 10;
        while (n != 0) {
            int cur = n % 10;
            n /= 10;
            if (cur > pre) {
                pre = 9;
                cur -= 1;
            }
            ans += to_string(pre);
            cout << "pre:" << pre << endl;
            cout << "ans:" << ans << endl;
            pre = cur;
        }
        ans += to_string(pre);
        reverse(ans.begin(), ans.end());
        return stoi(ans);
    }
};