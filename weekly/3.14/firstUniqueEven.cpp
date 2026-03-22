#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(50, 0);
        queue<int> Even;
        int first = -1;
        for (int num : nums) {
            if (num % 2 == 0) {
                f[num / 2]++;
                cout << num << endl;
                Even.push(num);
                if (f[num / 2] == 1) {
                    if (first == -1) first = num;
                } else {
                    if (num == first) {
                        while (!Even.empty() && f[Even.front() / 2] != 1) {
                            Even.pop();
                        }
                        if (Even.empty())
                            first = -1;
                        else
                            first = Even.front();
                    }
                }
            }
        }
        if (Even.empty() || first == -1) return -1;
        return first;
    }
};

int main() {
    vector<int> nums{4, 4, 10, 10};
    Solution sol;
    int re = sol.firstUniqueEven(nums);
    cout << re << endl;
    return 0;
}