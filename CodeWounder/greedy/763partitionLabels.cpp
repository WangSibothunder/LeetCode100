#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> partitionLabels(string s) {
        int inter = 0;
        vector<int> ans;
        unordered_map<char, int> StringToInter;
        unordered_map<int, int> InterToEnd;
        for (int i = 0; i < s.size(); i++) {
            char str = s[i];
            if (!StringToInter.count(str)) {
                StringToInter[str] = inter;
                InterToEnd[inter] = i;
                inter++;
            } else {
                int preInter = StringToInter[str];
                int preEnd = InterToEnd[preInter];
                InterToEnd[preInter] = i;
                int j;
                for (j = preEnd + 1; j < i; j++) {
                    char InnerStr = s[j];
                    int temp = -1;
                    if (InterToEnd.count(StringToInter[InnerStr])) {
                        inter--;
                        temp = InterToEnd[StringToInter[InnerStr]];
                        InterToEnd.erase(StringToInter[InnerStr]);
                    }
                    if (temp != -1) {
                        for (j; j <= temp; ++j) {
                            InnerStr = s[j];
                            StringToInter[InnerStr] = preInter;
                        }
                        j--;
                    }
                }
            }
        }
        for (int i = 0; i < inter; i++) {
            if (i == 0)
                ans.push_back(InterToEnd[i] + 1);
            else
                ans.push_back(InterToEnd[i] - InterToEnd[i - 1]);
        }
        return ans;
    }
};
int main() {
    string s = "ababcbacadefegdehijhklij";
    Solution sol;
    vector<int> re = sol.partitionLabels(s);
    return 0;
}