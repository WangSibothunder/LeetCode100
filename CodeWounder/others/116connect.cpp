#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> que, newQue;
        que.push(root);
        Node *pre, *cur;
        while (!que.empty()) {
            Node* Higher = que.front();
            que.pop();
            if (Higher->left) {
                if (!newQue.empty()) newQue.back()->next = Higher->left;
                newQue.push(Higher->left);
            }
            if (Higher->right) {
                newQue.back()->next = Higher->right;
                newQue.push(Higher->right);
            }
            if (que.empty()) {
                que = newQue;
                newQue = queue<Node*>();
            }
        }
        return root;
    }
};