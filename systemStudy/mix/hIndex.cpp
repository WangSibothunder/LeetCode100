#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> f(n + 1, 0);
        int ans = 0;
        for (auto cite : citations) {
            f[min(cite, n)]++;
        }
        int s = 0;
        for (int i = n; i > 0; i--) {
            s += f[i];
            if (s >= i) {
                return i;
            }
        }
        return ans;
    }
};