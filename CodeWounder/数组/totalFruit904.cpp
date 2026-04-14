#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() == 1) return 1;
        if (fruits.size() == 2) return 2;
        int type1 = -1, type2 = -1;
        int type1_num = 0, type2_num = 0;
        int type1_last = -1, type2_last = -1;
        int maxFruit = INT_MIN;
        fruits.push_back(-2);
        // fruits.push_back(-3);
        for (int i = 0; i < fruits.size(); i++) {
            if (type1 == -1) {
                type1 = fruits[i];
                type1_last = i;
                type1_num = 1;
            } else if (type2 == -1 && type1 != fruits[i] && fruits[i] != -2) {
                type2 = fruits[i];
                type2_last = i;
                type2_num = 1;
            } else if ((fruits[i] != type1 && fruits[i] != type2)) {
                maxFruit = max(maxFruit, type1_num + type2_num);
                if (fruits[i - 1] == type2) {
                    type2_num = i - type1_last - 1;
                    type1 = fruits[i];
                    type1_last = i;
                    type1_num = 1;
                } else if (fruits[i - 1] == type1) {
                    type1_num = i - type2_last - 1;
                    type2 = fruits[i];
                    type2_last = i;
                    type2_num = 1;
                }
            } else {
                if (fruits[i] == type1) {
                    type1_num++;
                    type1_last = i;
                } else if (fruits[i] == type2) {
                    type2_num++;
                    type2_last = i;
                }
            }
        }
        if (type2 == -1) return fruits.size() - 1;
        return maxFruit;
    }
};
int main() {
    vector<int> fruits(4, 3);
    Solution sol;
    int re = sol.totalFruit(fruits);
    cout << re << endl;
    return 0;
}