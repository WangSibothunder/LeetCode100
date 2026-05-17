#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    string predictPartyVictory(string senate) {
        int numR = 0, numD = 0;
        for (auto& ele : senate) {
            if (ele == 'R')
                numR++;
            else
                numD++;
        }
        vector<int> visited(senate.size());
        int index = 0, indexNxt = 0;
        while (numD != 0 && numR != 0) {
            if (visited[index]) {
                index = (index + 1) % senate.size();
                continue;
            }
            indexNxt = (index + 1) % senate.size();
            if (senate[index] == 'R') {
                numD--;
                if (numD) {
                    while (senate[indexNxt] != 'D' || visited[indexNxt]) {
                        indexNxt = (indexNxt + 1) % senate.size();
                    }
                    visited[indexNxt] = 1;
                }
            } else {
                numR--;
                if (numR) {
                    while (senate[indexNxt] != 'R' || visited[indexNxt]) {
                        indexNxt = (indexNxt + 1) % senate.size();
                    }
                }
            }
            cout << index << " " << indexNxt << " " << senate[index] << " "
                 << senate[indexNxt] << endl;
            index = (index + 1) % senate.size();
            visited[indexNxt] = 1;
        }
        if (numD != 0) return "Dire";
        return "Radiant";
    }
};