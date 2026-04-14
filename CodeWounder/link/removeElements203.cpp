#include "link.h"
class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new (ListNode);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};