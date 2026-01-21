#include "link.h"
/*
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
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<int, Node *> Registry_random;

        Node *ans = new Node(head->val);
        while (ans != nullptr)
        {
            ans->val = head->val;
            if (head->random == nullptr)
                ans->random = nullptr;
            else
            {
                if (Registry_random.count(head->random->val) == 0)
                {
                    Node *newNode = new Node(head->random->val);
                    Registry_random[head->random->val] = newNode;
                }
                ans->random = Registry_random[ans->random->val];
            }
            if (head->next != nullptr)
            {
                Node *newNode = new Node(head->next->val);
                ans->next = newNode;
            }
            else
                ans->next = nullptr;
            head = head->next;
            ans = ans->next;
        }
        return ans;
    }
};