#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minOperations(string s1, string s2) {
        int len = s1.size();
        vector<int> dp(len + 1);
        for (int i = 1; i <= len; i++) {
            if (dp[i - 1] != INT_MIN && s1[i - 1] == s2[i - 1])
                dp[i] = dp[i - 1];
            else {
                if (s1[i - 1] == '0' && s2[i - 1] == '1')
                    dp[i] = dp[i - 1] + 1;
                else {
                    if (i == 1)
                        dp[i] = INT_MIN;
                    else {
                        if (s1.substr(i - 2, 2) == "01") {
                            if (s2.substr(i - 2, 2) == "00")
                                dp[i] = dp[i - 2] + 2;
                            else if (s2.substr(i - 2, 2) == "01")
                                dp[i] = dp[i - 2];
                            else if (s2.substr(i - 2, 2) == "10")
                                dp[i] = dp[i - 2] + 3;
                            else if (s2.substr(i - 2, 2) == "11")
                                dp[i] = dp[i - 2] + 1;
                        } else if (s1.substr(i - 2, 2) == "11") {
                            if (s2.substr(i - 2, 2) == "00")
                                dp[i] = dp[i - 2] + 1;
                            else if (s2.substr(i - 2, 2) == "01")
                                dp[i] = dp[i - 2] + 2;
                            else if (s2.substr(i - 2, 2) == "10")
                                dp[i] = dp[i - 2] + 2;
                            else if (s2.substr(i - 2, 2) == "11")
                                dp[i] = dp[i - 2] + 0;
                        } else if (s1.substr(i - 2, 2) == "10") {
                            if (s2.substr(i - 2, 2) == "01")
                                dp[i] = dp[i - 2] + 2;
                            else if (s2.substr(i - 2, 2) == "01")
                                dp[i] = dp[i - 2] + 2;
                            else if (s2.substr(i - 2, 2) == "10")
                                dp[i] = dp[i - 2];
                            else if (s2.substr(i - 2, 2) == "11")
                                dp[i] = dp[i - 2] + 1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < len; i++) cout << dp[i] << " ";
        return dp[len] == INT_MIN ? -1 : dp[len];
    }
};
// ©leetcode
// ©leetcode