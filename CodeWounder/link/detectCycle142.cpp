#include "link.h"
class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *fast = new (ListNode), *slow = new (ListNode);
        int step = 0, start = 0;
        while (start == 0 || fast != nullptr && fast != slow) {
            if (start == 0) start = 1;
            fast = fast->next->next;
            slow = slow->next;
            step++;
        }
        if (fast == nullptr) return fast;
        while (slow != head) {
            slow = slow->next;
            head = head->next;
        }
        return head;
    }
};