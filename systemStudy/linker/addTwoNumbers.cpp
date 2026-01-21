#include "link.h"
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = l1;
        int carry = 0;
        while (l1->next != nullptr && l2->next != nullptr)
        {
            // 两个数都是有值的
            int temp = l1->val + l2->val + carry;
            l1->val = temp % 10;
            carry = temp / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        int temp = l1->val + l2->val + carry;
        l1->val = temp % 10;
        carry = temp / 10;
        if (l1->next == nullptr && l2->next)
        {
            l1->next = l2->next;
            l2->next->val += carry;
        }
        else if (l1->next && l2->next == nullptr)
        {
            l1->next->val += carry;
        }
        else
        {
            if (carry == 1)
            {
                ListNode *appendx = new ListNode(1);
                l1->next = appendx;
            }
        }
        while (l1->next != nullptr)
        {
            l1 = l1->next;
            int temp = l1->val;
            l1->val = temp % 10;
            carry = temp / 10;
            if (carry == 0)
            {
                break;
            }
            if (l1->next == nullptr && carry == 1)
            {
                ListNode *appendx = new ListNode(1);
                l1->next = appendx;
                break;
            }
            else
            {
                l1->next->val += carry;
            }
        }
        return dummy->next;
    }
};
int main()
{
    Solution a;
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(4);
    ListNode *n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;

    ListNode *m1 = new ListNode(5);
    ListNode *m2 = new ListNode(6);
    ListNode *m3 = new ListNode(7);
    m1->next = m2;
    m2->next = m3;

    ListNode *ans = a.addTwoNumbers(n1, m1);
    while (ans != nullptr)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    printf("\n");
    return 0;
}