#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int num = 0;
int main() {
    scanf("%d", &num);
    unordered_set<string> uset;
    queue<queue<string>> graph;
    string beginStr, endStr;
    cin >> beginStr >> endStr;
    int wordLen = beginStr.size();
    for (int i = 0; i < num; i++) {
        string temp;
        cin >> temp;
        uset.insert(temp);
    }
    queue<string> st;
    st.push(beginStr);
    uset.erase(beginStr);
    graph.push(st);
    int step = 0;
    while (!graph.empty()) {
        queue<string> curqueue = graph.front();
        graph.pop();
        step++;
        while (!curqueue.empty()) {
            string cur = curqueue.front();
            curqueue.pop();
            queue<string> nextqueue;
            for (int change = 0; change < wordLen; change++) {
                string tempcur = cur;
                for (int newstr = 0; newstr < 26; newstr++) {
                    tempcur[change] = 'a' + newstr;
                    if (tempcur == endStr) {
                        printf("%d\n", step + 1);
                        return 0;
                    } else if (uset.count(tempcur)) {
                        nextqueue.push(tempcur);
                        uset.erase(tempcur);
                    }
                }
            }
            if (!nextqueue.empty()) graph.push(nextqueue);
        }
    }
    printf("%d\n", 0);
    return 0;
}
