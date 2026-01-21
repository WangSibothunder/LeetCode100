#include "link.h"
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        bool ans = false;
        ListNode *slow = head;
        ListNode *fast = head;
        if (slow->next == nullptr)
            return ans;
        fast = fast->next;
        while (slow != fast && fast != nullptr && fast->next != nullptr)
        {
            // 需要保证快指针可以跑
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == slow)
            ans = true;
        return ans;
    }
};
int main()
{
    Solution a;
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(0);
    ListNode *n4 = new ListNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    bool ans = a.hasCycle(n1);
    printf("是否有环：%d\n", ans);
    return 0;
}