#include "ListNode.h"
#include <vector>
using namespace std;

class Solution
{
public:
    // 反转 [head, tail] 区间，返回新头和新尾
    pair<ListNode*, ListNode*> Reverse(ListNode *head, ListNode *tail) {
        ListNode* prev = tail->next; // 反转后新尾要指向的节点
        ListNode* cur = head;
        while (prev!= tail) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // prev 已经是新头，head 是新尾
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* group_prev = dummy; // 每组翻转前的节点
        ListNode* slow = head;

        while (slow) {
            ListNode* fast = slow;
            // 找到本组的尾节点
            for (int i = 1; i < k; i++) {
                if (!fast->next) return dummy->next; // 剩余不足k个，不翻转
                fast = fast->next;
            }
            ListNode* next_group = fast->next; // 下一组的起点

            // 反转本组
            auto [new_head, new_tail] = Reverse(slow, fast);

            // 连接前后
            group_prev->next = new_head;
            new_tail->next = next_group;

            // 移动指针准备下一组
            group_prev = new_tail;
            slow = next_group;

            // 调试输出：可打印每组翻转后的链表
            // ListNode* p = dummy->next;
            // while (p) { printf("%d ", p->val); p = p->next; }
            // printf("\n");
        }
        return dummy->next;
    }
};