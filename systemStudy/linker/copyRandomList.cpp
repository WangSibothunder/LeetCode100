#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node *, Node *> mapping;

        // First pass: create all nodes
        Node *curr = head;
        while (curr != nullptr)
        {
            mapping[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: set next and random pointers
        curr = head;
        while (curr != nullptr)
        {
            if (curr->next != nullptr)
                mapping[curr]->next = mapping[curr->next];
            if (curr->random != nullptr)
                mapping[curr]->random = mapping[curr->random];
            curr = curr->next;
        }

        return mapping[head];
    }
};

int main()
{
    // Test code here
    return 0;
}