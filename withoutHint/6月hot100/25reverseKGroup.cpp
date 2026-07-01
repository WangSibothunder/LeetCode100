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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        if (!cur || !cur->next) return cur;
        ListNode *nxt = head->next, *fast = dummy;
        for (int i = 0; i < k; i++) fast = fast->next;
        while (cur && nxt) {
            if (!fast) break;
            for (int i = 0; i < k - 1; i++) {
                cout << fast << endl;
                if (fast) fast = fast->next;
                if (!nxt) break;
                // cout << nxt->val << " ";
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next;
            }
            if (!cur->next || !cur->next->next) break;
            pre = cur;
            cur = cur->next;
            nxt = cur->next;
            fast = fast->next;
        }
        return dummy->next;
    }
};