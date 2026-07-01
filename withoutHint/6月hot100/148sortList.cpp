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
    ListNode* sortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* ord = dummy;
        while (ord->next) {
            ListNode *pre = new ListNode(INT_MAX), *cur = new ListNode(INT_MAX);
            pre->next = cur;
            head = ord;
            while (head->next) {
                if (head->next->val < pre->next->val) {
                    pre = head;
                }
                head = head->next;
            }
            cur = pre->next;
            pre->next = cur->next;
            cur->next = ord->next;
            ord->next = cur;
            ord = ord->next;
        }
        return dummy->next;
    }
};