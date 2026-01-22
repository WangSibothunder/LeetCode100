#include "link.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        else if (list1 != nullptr && list2 == nullptr)
            return list1;
        else if (list1 == nullptr && list2 != nullptr)
            return list2;
        ListNode *dummy = new ListNode(0);
        if (list1->val <= list2->val)
            dummy->next = list1;
        else
            dummy->next = list2;

        while (list1 != nullptr && list2 != nullptr)
        {

            ListNode *cur = new ListNode;
            bool flag1 = 0;
            while (list2 != nullptr && list1->val > list2->val)
            {
                cur = list2;
                list2 = list2->next;
                flag1 = 1;
            }
            if (flag1)
                cur->next = list1;
            bool flag2 = 0;
            while (list2 != nullptr && list1 != nullptr && list1->val <= list2->val)
            {
                cur = list1;
                list1 = list1->next;
                flag2 = 1;
            }
            if (flag2)
                cur->next = list2;
        }
        return dummy->next;
    }
};
int main()
{
    Solution s;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(5);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *res = s.mergeTwoLists(l1, l2);
    while (res != nullptr)
    {
        printf("%d ", res->val);
        res = res->next;
    }
    printList(res);
    return 0;
}