#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> umap;
        umap[5] = 0, umap[10] = 0;
        for (int i = 0; i < bills.size(); i++) {
            int cash = bills[i];
            if (cash == 5) umap[5]++;
            if (cash == 10) {
                if (umap[5] == 0) return false;
                umap[10]++, umap[5]--;
            }
            if (cash == 20) {
                if (umap[10] != 0) {
                    umap[10]--;
                    cash -= 10;
                    if (umap[5] == 0) return false;
                    umap[5]--;
                } else if (umap[5] >= 3) {
                    umap[5] -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};