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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        while (nxt != nullptr) {
            if (cur->val != nxt->val) {
                pre = cur;
                cur = nxt;
                nxt = cur->next;
            } else {
                while (nxt != nullptr && cur->val == nxt->val) {
                    cur = nxt;
                    nxt = cur->next;
                }
                pre->next = nxt;
                cur = pre;
            }
        }
        return dummy->next;
    }
};