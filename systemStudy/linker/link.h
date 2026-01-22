#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode() : val(0), next(nullptr), random(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
};
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
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("nullptr\n");
}