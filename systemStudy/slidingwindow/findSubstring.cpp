#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        if (words.empty() || s.empty())
            return ans;
        int words_size = words.size(), s_size = s.size(), word_lenth = words[0].size();
        if (s_size < words_size * word_lenth)
            return ans;
        unordered_map<string, int> hushmap;
        for (auto &word : words)
        {
            hushmap[word]++;
        } // 初始化标记
        for (int offset = 0; offset < word_lenth; offset++)
        {
            int left = offset, count = 0; // left为当前左起点，count表示有多少单词符合
            unordered_map<string, int> windows;
            for (int j = offset; j + word_lenth <= s_size; j += word_lenth)
            { // j遍历当前offset下的所有单词
                string temp = s.substr(j, word_lenth);
                if (hushmap.count(temp))
                {

                    windows[temp]++;
                    count++;
                    while (windows[temp] > hushmap[temp])
                    {
                        string leftWord = s.substr(left, word_lenth);
                        windows[leftWord]--;
                        count--;
                        left += word_lenth;
                    }
                    if (count == words_size)
                    {
                        ans.push_back(left);
                        string leftWord = s.substr(left, word_lenth);
                        windows[leftWord]--;
                        count--;
                        left += word_lenth;
                    }
                }
                else
                {
                    left = j + word_lenth; // 当前这个词不正确，那就从这个词的下一个词开始研究
                    windows.clear();
                    count = 0;
                }
            }
        }

        return ans;
    }
};
int main()
{
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    auto res = sol.findSubstring(s, words);
    for (int x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}