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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) return head;
        ListNode* cur = head;
        int len = 1;
        while (cur->next != nullptr) {
            cur = cur->next;
            len++;
        }
        cur->next = head;
        ListNode* nxt = head;
        for (int i = 0; i < (len - k % len); i++) {
            cur = nxt;
            nxt = cur->next;
        }
        cur->next = nullptr;
        return nxt;
    }
};