#include "link.h"
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        dummy->next = l1;
        ListNode *pre = dummy, *cur = l1;
        int carry = 0;
        while (l1 && l2) {
            l1->val = l1->val + l2->val + carry;
            if (l1->val >= 10) {
                carry = 1;
                l1->val -= 10;
            } else
                carry = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            l1->val = l1->val + carry;
            if (l1->val >= 10) {
                carry = 1;
                l1->val -= 10;
            } else
                carry = 0;
            pre = l1;
            l1 = l1->next;
        }
        if (l2) {
            l1 = l2;
            pre->next = l1;
            while (l2) {
                l1->val = l2->val + carry;
                if (l1->val >= 10) {
                    carry = 1;
                    l1->val -= 10;
                } else
                    carry = 0;
                pre = l1;
                l2 = l2->next;
                l1 = l1->next;
            }
        }
        if (carry) {
            l1 = new ListNode(1);
            pre->next = l1;
        }
        return dummy->next;
    }
};