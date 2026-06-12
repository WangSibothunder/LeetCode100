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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *pre = dummy, *cur = head, *nxt = head->next;
        while (nxt) {
            pre->next = nxt;
            cur->next = nxt->next;
            nxt->next = cur;
            pre = cur;
            cur = cur->next;
            if (cur) nxt = cur->next;
        }
        return dummy->next;
    }
};