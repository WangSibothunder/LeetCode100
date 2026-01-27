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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessHead = new ListNode(0), *lessHeadCur = new ListNode(-101);
        ListNode *moreHead = new ListNode(0), *moreHeadCur = new ListNode(-101);
        lessHead->next = nullptr;
        moreHead->next = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            if (cur->val < x) {
                if (lessHeadCur->val == -101) {
                    lessHeadCur = cur;
                    lessHead->next = lessHeadCur;
                    lessHeadCur->next = nullptr;
                }

                else {
                    lessHeadCur->next = cur;
                    lessHeadCur = cur;
                    lessHeadCur->next = nullptr;
                }
            } else {
                if (moreHeadCur->val == -101) {
                    moreHeadCur = cur;
                    moreHead->next = moreHeadCur;
                    moreHeadCur->next = nullptr;
                } else {
                    moreHeadCur->next = cur;
                    moreHeadCur = cur;
                    moreHeadCur->next = nullptr;
                }
            }
            cur = nxt;
        }
        lessHeadCur->next = moreHead->next;
        return (lessHeadCur->val == -101) ? lessHeadCur->next : lessHead->next;
    }
};
int main() {
    ListNode* n1 = new ListNode(1);
    // ListNode* n2 = new ListNode(4);
    // ListNode* n3 = new ListNode(3);
    // ListNode* n4 = new ListNode(2);
    // ListNode* n5 = new ListNode(5);
    // ListNode* n6 = new ListNode(2);
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // n5->next = n6;
    Solution s;
    ListNode* res = s.partition(n1, 0);
    return 0;
}