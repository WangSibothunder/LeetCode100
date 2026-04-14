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
        ListNode* dummy = new (ListNode);
        if (head == nullptr || head->next == nullptr) return head;
        dummy->next = head;
        ListNode *pre = dummy, *cur = head, *nxt = head->next;
        while (nxt != nullptr) {
            pre->next = nxt;
            cur->next = nxt->next;
            nxt->next = cur;
            pre = cur;
            cur = cur->next;
            nxt = cur ? cur->next : nullptr;
        }
        return dummy->next;
    }
};