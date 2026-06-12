#include "link.h"  //
// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};  //

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> umap;  // org->new
        Node* newHead = new Node(head->val);
        Node *dummy = new Node(0), *dummy_org = new Node(0);
        dummy->next = newHead;
        dummy_org->next = head;
        while (head) {
            if (head->next) newHead->next = new Node(head->next->val);
            cout << head->val << " " << newHead->val << endl;
            umap[head] = newHead;
            head = head->next;
            newHead = newHead->next;
        }
        newHead = dummy->next;
        head = dummy_org->next;
        while (head) {
            if (head->random) newHead->random = umap[head->random];
            head = head->next;
            newHead = newHead->next;
        }
        return dummy->next;
    }
};