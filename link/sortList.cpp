#include "ListNode.h"
using namespace std;
class Solution
{
    // 将链表对半分，如果是奇数，则让后半段长
    ListNode* middleNode(ListNode *head)
    {
        ListNode *pre = head, *slow = head, *fast = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return slow;
    }
    // 假如两个链表分别是有序的，那么用归并排序让他们变成有序
    ListNode* mergeTwoList(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0, nullptr);
        ListNode *cur = dummy;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy->next;
    }

public:
    ListNode* sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* head2 = middleNode(head);
        head = sortList(head);
        head2 = sortList(head2);
        return mergeTwoList(head,head2);
        
    }
};