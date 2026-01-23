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
        int n = 0;  // n为数组长度
        ListNode* p0 = head;
        while (p0) {
            p0 = p0->next;
            n++;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        ListNode* startRev = pre;
        while (n >= k) {
            for (int i = 0; i < k; i++) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            startRev->next->next = cur;
            nxt = startRev->next;
            startRev->next = pre;
            startRev = nxt;
            n -= k;
        }
        return dummy->next;
    }
};
int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    node1->next = node2;
    ListNode* node3 = new ListNode(4);
    node2->next = node3;
    ListNode* node4 = new ListNode(5);
    node3->next = node4;
    head->next = node1;
    printList(s.reverseKGroup(head, 2));
    return 0;
}