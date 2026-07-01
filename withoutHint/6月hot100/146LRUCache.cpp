#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct myList {
    int key;
    int val;
    myList* pre;
    myList* next;
    myList() : key(0), val(0), pre(nullptr), next(nullptr) {}
    myList(int x) : key(0), val(x), pre(nullptr), next(nullptr) {}
    myList(int x, myList* next) : val(x), pre(nullptr), next(next) {}
};
void logp(myList* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
class LRUCache {
    myList* dummy = new myList();
    myList* tail = dummy;
    int num = 0;
    unordered_map<int, myList*> umap;
    int capacity;

   public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        cout << "get " << key << endl;
        if (!umap[key] || umap[key]->val == -1) {
            cout << "not find" << endl;
            return -1;
        }
        myList* find = umap[key];
        if (tail == find) return tail->val;
        find->pre->next = find->next;
        tail->next = find;
        find->pre = tail;
        find->next = nullptr;
        tail = find;
        logp(dummy->next);
        return find->val;
    }

    void put(int key, int value) {
        cout << "put " << key << " : " << value << endl;
        if (get(key) == -1) {
            // cout << "insertNew";
            myList* inNew = new myList();
            inNew->val = value, inNew->key = key;
            inNew->pre = tail;
            num++;
            tail->next = inNew;
            umap[key] = inNew;
            tail = inNew;
            // logp(dummy->next);
            if (num > capacity) {
                num--;
                umap[dummy->next->key]->val = -1;
                dummy = dummy->next;
                tail = inNew;
            }
        } else
            umap[key]->val = value;
        logp(dummy->next);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */