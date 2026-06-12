#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Trie {
    unordered_set<string> uset, prefixUset;

   public:
    Trie() {}

    void insert(string word) {
        uset.insert(word);
        for (int i = 1; i < word.size(); i++) {
            string s = word.substr(0, i);
            if (!prefixUset.count(s)) prefixUset.insert(s);
        }
    }

    bool search(string word) { return uset.count(word); }

    bool startsWith(string prefix) {
        /*如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true
         * ；否则，返回 false 。*/
        return prefixUset.count(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */