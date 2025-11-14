#include <iostream>
#include <vector>
using namespace std;
#define ll long long
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int f_mx = 1, f_mn = 1;
        int ans = INT_MIN;
        for (auto x : nums)
        {
            int mx = f_mx;
            f_mx = max({x, f_mx * x, f_mn * x});
            f_mn = min({x, mx * x, f_mn * x});
            ans = max(ans, f_mx);
        }
        return ans;
    }
};