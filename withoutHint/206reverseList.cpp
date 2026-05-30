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
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy->next;
        ListNode* nxt = cur->next;
        while (nxt) {
            cur->next = nxt->next;
            nxt->next = dummy->next;
            dummy->next = nxt;
            nxt = cur->next;
        }
        return dummy->next;
    }
};