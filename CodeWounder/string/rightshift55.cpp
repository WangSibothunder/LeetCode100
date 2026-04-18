#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int k;
    string s;
    scanf("%d", &k);
    cin >> s;
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    cout << s << endl;
    return 0;
}