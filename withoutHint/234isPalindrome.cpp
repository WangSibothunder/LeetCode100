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
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode();
        int len = 0;
        dummy->next = head;
        ListNode *fast = dummy, *slow = dummy;
        while (!fast && !fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) {
            // 偶数个,反转到slow就可以
            if (slow->next == fast) return slow->val == fast->val;
            ListNode *cur = head, *nxt = head->next;
            ListNode* aim = slow->next;
            while (nxt != aim) {
                cur->next = nxt->next;
                nxt->next = dummy->next;
                dummy->next = nxt;
                nxt = cur->next;
            }
            while (!nxt) {
                if (slow->val != nxt->val) return false;
                slow = slow->next;
                nxt = nxt->next;
            }
        } else {
            if (!slow->next->next) return dummy->next->val == slow->next->val;
            ListNode *cur = head, *nxt = head->next;
            while (nxt != slow) {
                cur->next = nxt->next;
                nxt->next = dummy->next;
                dummy->next = nxt;
                nxt = cur->next;
            }
            while (!nxt) {
                if (slow->val != nxt->val) return false;
                slow = slow->next;
                nxt = nxt->next;
            }
        }
        return true;
    }
};