// ...existing code...
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        int bestL = 0, bestR = 0; // [bestL, bestR)
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) { --l; ++r; }
            return pair<int,int>(l+1, r); // 返回符合的区间 [l+1, r)
        };
        for (int i = 0; i < n; ++i) {
            // 奇数长度中心 i
            auto p1 = expand(i, i);
            if (p1.second - p1.first > bestR - bestL) { bestL = p1.first; bestR = p1.second; }
            // 偶数长度中心 i, i+1
            auto p2 = expand(i, i+1);
            if (p2.second - p2.first > bestR - bestL) { bestL = p2.first; bestR = p2.second; }
        }
        return s.substr(bestL, bestR - bestL);
    }
};
int main(){
    string in = "babad";
    Solution a;
    string out = a.longestPalindrome(in);
    cout << out << endl;
    return 0;
}
// ...existing code...