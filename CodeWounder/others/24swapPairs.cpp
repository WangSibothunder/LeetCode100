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
        if (cur == nullptr) return head;
        ListNode* dummy = new (ListNode);
        dummy->next = head;
        ListNode *pre, *cur, *nxt;
        pre = dummy, cur = head, nxt = head->next;
        while (nxt != nullptr) {
            cur->next = nxt->next;
            nxt->next = cur;
            pre->next = nxt;
            pre = cur;
            cur = cur->next;
            if (cur == nullptr) break;
            nxt = cur->next;
        }
        return dummy->next;
    }
};