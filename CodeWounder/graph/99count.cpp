#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> uset;

int bfs(string beginStr, string endStr) {
    int len = beginStr.size();
    queue<string> que;
    queue<string> nxtQue;
    que.push(beginStr);
    int times = 2;
    while (!que.empty()) {
        string org = que.front();
        que.pop();
        // cout << org << " ";
        for (int j = 0; j < len; j++) {
            string temp = org;
            for (int i = 0; i < 26; i++) {
                temp[j] = 'a' + i;
                if (temp == endStr) return times;
                if (uset.count(temp) && uset[temp] == 0) {
                    // cout << temp[i] << endl;
                    nxtQue.push(temp);
                    uset[temp] = 1;
                }
            }
        }
        if (que.empty()) {
            times++;
            cout << endl;
            que = nxtQue;
            nxtQue = queue<string>();
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    string beginStr, endStr;
    cin >> beginStr >> endStr;
    for (int j = 0; j < n; j++) {
        string temp;
        cin >> temp;
        uset[temp] = 0;
    }
    cout << bfs(beginStr, endStr) << endl;
    return 0;
}