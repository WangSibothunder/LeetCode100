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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<ListNode*> head_k(k);
        for (int i = 0; i < k; i++) {
            head_k[i] = lists[i];
        }
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        int flag = 1;
        while (flag) {
            int tempIdx = 0, tempVal = INT_MAX;
            flag = 0;
            for (int i = 0; i < k; i++) {
                if (head_k[i]) {
                    flag = 1;
                    if (head_k[i]->val < tempVal) {
                        tempIdx = i;
                        tempVal = head_k[i]->val;
                    }
                }
            }
            if (flag) {
                tail->next = head_k[tempIdx];
                tail = head_k[tempIdx];
                head_k[tempIdx] = head_k[tempIdx]->next;
            }
        }
        return dummy->next;
    }
};