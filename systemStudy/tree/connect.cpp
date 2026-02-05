#include "tree.h"
class Solution {
   public:
    Node* connect(Node* root) {
        queue<Node*> cur;
        queue<Node*> nxt;
        cur.push(root);
        while (!cur.empty()) {
            Node* node = cur.front();
            cur.pop();
            if (node->left) nxt.push(node->left);
            if (node->right) nxt.push(node->right);
            if (cur.empty()) {
                cur = nxt;
                if (!nxt.empty()) {
                    node = nxt.front();
                    nxt.pop();
                    while (!nxt.empty()) {
                        node->next = nxt.front();
                        node = nxt.front();
                        nxt.pop();
                    }
                }
            }
        }
    }
};