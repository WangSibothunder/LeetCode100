#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string sgood = "";
        for (auto &ch : s)
        {
            if (isalnum(ch))
                sgood += tolower(ch);
        }
        cout << sgood << "\n";
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (sgood[left] != sgood[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    string in = "A man, a plan, a canal: Panama";
    Solution a;
    a.isPalindrome(in);
    return 0;
}