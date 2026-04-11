#include "link.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0, lenB = 0;
        ListNode *dummyA = new (ListNode), *dummyB = new (ListNode);
        dummyA->next = headA, dummyB->next = headB;
        while (headA) {
            lenA++;
            headA = headA->next;
        }
        while (headB) {
            lenB++;
            headB = headB->next;
        }
        headA = dummyA->next;
        headB = dummyB->next;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                headB = headB->next;
            }
        }
        while (headA != nullptr && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};