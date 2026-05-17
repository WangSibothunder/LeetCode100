#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, int> umap;
        for (int i = 0; i < wordList.size(); i++) {
            umap[wordList[i]] = 0;
        }
        queue<string> que, newQue;
        int cnt = 0;
        que.push(beginWord);
        while (!que.empty()) {
            string cur = que.front();
            que.pop();
            for (int i = 0; i < cur.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    string temp = cur;
                    temp[i] = j + 'a';
                    if (temp == endWord) return cnt + 1;
                    if (umap.count(temp) && umap[temp] == 1) {
                        umap[temp] = 1;
                        newQue.push(temp);
                    }
                }
            }
            if (que.empty()) {
                cnt++;
                que = newQue;
                newQue = queue<string>();
            }
        }
        return -1;
    }
};