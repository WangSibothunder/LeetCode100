struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyhead = new ListNode(0, head);
        ListNode *temp = dummyhead;
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            ListNode *fast = temp->next->next;
            ListNode *slow = temp->next;
            temp->next = fast;
            slow->next = fast->next;
            fast->next = slow;
            temp = slow;
        }
        return dummyhead->next;
    }
};