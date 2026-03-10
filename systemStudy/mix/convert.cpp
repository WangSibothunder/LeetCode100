#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        int n = s.size();                 // original len
        int numPair = (numRows - 1) * 2;  // one ZigZag
        int numFullRow = numRows + ((n - numRows) / numPair + 1) *
                                       numPair;  // 补全之后的长度
        string f(n, '1');
        int newIdx = 0, OrgIdx = 0;
        int hopLen = numPair;
        for (int rowIdx = 0; rowIdx < numRows; rowIdx++) {
            int temp_hop = hopLen;
            OrgIdx = rowIdx;
            while (OrgIdx < numFullRow) {
                if (OrgIdx >= n) break;
                if (temp_hop) {
                    f[newIdx] = s[OrgIdx];
                    newIdx++;
                    OrgIdx += temp_hop;
                }
                temp_hop = numPair - temp_hop;
            }
            hopLen -= 2;
        }
        return f;
    }
};

int main() {
    string test = "PAYPALISHIRING";
    int numRows = 3;
    Solution sol;
    string re = sol.convert(test, numRows);
    cout << re << endl;
    return 0;
}