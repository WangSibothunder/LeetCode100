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
        int aLen = 0, bLen = 0;
        ListNode *dummyA = new ListNode(0), *dummyB = new ListNode(0);
        dummyA->next = headA, dummyB->next = headB;
        while (headA != nullptr) {
            headA = headA->next;
            aLen++;
        }
        while (headB != nullptr) {
            headB = headB->next;
            bLen++;
        }
        headA = dummyA->next;
        headB = dummyB->next;
        while (aLen > bLen) {
            headA = headA->next;
            aLen--;
        }
        while (bLen > aLen) {
            headB = headB->next;
            bLen--;
        }
        while (headA != nullptr) {
            if (headA == headB) break;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};