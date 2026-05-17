#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    bool isLongPressedName(string name, string typed) {
        int indexName = 0, indexTyped = 0;
        name += '_';
        typed += '_';  // 用a结尾可能为导致撞车
        while (indexName != name.size() - 1 && indexTyped != typed.size() - 1) {
            printf("indexName:%d,indexTyped:%d\nname:%c,typed:%c\n", indexName,
                   indexTyped, name[indexName], typed[indexTyped]);
            if (name[indexName] == typed[indexTyped] &&
                name[indexName] == name[indexName + 1]) {
                indexName++;
                indexTyped++;
            } else if (name[indexName] == typed[indexTyped] &&
                       typed[indexTyped] == typed[indexTyped + 1]) {
                indexTyped++;
            } else if (name[indexName] == typed[indexTyped]) {
                indexName++;
                indexTyped++;
            }
            if (name[indexName] != typed[indexTyped]) return false;
        }
        return true;
    }
};