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
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* dummy = new ListNode();
        ListNode *pre = new ListNode(), *cur = new ListNode();
        // pre = dummy;
        if (list1->val > list2->val) {
            dummy->next = list2;
            cur = list2;
            list2 = list2->next;
        } else {
            dummy->next = list1;
            cur = list1;
            list1 = list1->next;
        }
        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                // pre = cur;
                cur = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                cur = list1;
                list1 = list1->next;
            }
        }
        if (list1)
            cur->next = list1;
        else
            cur->next = list2;
        return dummy->next;
    }
};