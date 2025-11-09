#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    const string digital_mapping[10] = // 映射每个数字所代表字母集合
        {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz", // 9
    };
    vector<string> result;
    string path;
    void backtracking(string digits, int index)
    {
        if (index == digits.size())
        {
            result.push_back(path);
            return;
        }
        int digital_num = digits[index] - '0';
        string letter = digital_mapping[digital_num];
        for (int i = 0; i < letter.size(); i++)
        {
            path.push_back(letter[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return result;
        backtracking(digits, 0);
        return result;
    }
};