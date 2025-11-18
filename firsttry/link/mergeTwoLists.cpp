
// Definition for singly-linked list.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode Prehead = ListNode(-1);
        ListNode *ans = &Prehead;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                ans->next = list1;
                ans = list1;
                list1 = list1->next;
            }
            else
            {
                ans->next = list2;
                ans = list2;
                list2 = list2->next;
            }
        }
        while (list1 != nullptr)
        {
            ans->next = list1;
            ans = list1;
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            ans->next = list2;
            ans = list2;
            list2 = list2->next;
        }
        return Prehead.next;
    }
};