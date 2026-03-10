#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> uset;

        int n = magazine.size();
        int m = ransomNote.size();
        for (int i = 0; i < n; i++) {
            if (uset.count(magazine[i]))
                uset[magazine[i]]++;
            else
                uset.insert({magazine[i], 1});
        }
        for (int i = 0; i < m; i++) {
            if (!uset.count(ransomNote[i]) || uset[ransomNote[i]] == 0)
                return 0;
            uset[ransomNote[i]]--;
        }
        return 1;
    }
};