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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new (ListNode);
        dummy->next = head;
        if (head->next == nullptr) return head;
        ListNode *pre = dummy, *cur = head, *nxt = head->next;
        while (nxt) {
            cur->next = pre;
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        nxt->next = cur;
        head->next = nullptr;
        return nxt;
    }
};