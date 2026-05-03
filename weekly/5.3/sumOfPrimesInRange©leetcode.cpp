#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    bool isPrime(int n) {
        if (n % 2 == 0) return false;
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string org = to_string(n);
        reverse(org.begin(), org.end());
        int reverseN = stoi(org);
        if (reverseN < n) swap(reverseN, n);
        int ans = 0;
        for (int i = n; i <= reverseN; i++) {
            if (isPrime(i)) ans += i;
        }
        return ans;
    }
};
int main() {
    int n = 100;
    Solution sol;
    int re = sol.sumOfPrimesInRange(n);
    cout << re << endl;
    return 0;
}