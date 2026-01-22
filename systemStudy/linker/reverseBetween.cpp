#include "link.h"
// #include <iostream>
// #include <cstdio>
// using namespace std;
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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right) return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        // 找到反转起始位置的前一个节点
        ListNode *prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // 开始反转部分的起始节点
        ListNode *current = prev->next;
        
        // 反转指定范围内的节点
        for (int i = 0; i < right - left; ++i) {
            ListNode *next_node = current->next;
            current->next = next_node->next;
            next_node->next = prev->next;
            prev->next = next_node;
        }
        
        ListNode *result = dummy->next;
        delete dummy;  // 清理临时节点
        return result;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    ListNode *res = s.reverseBetween(head, 2, 4);
    while (res != nullptr)
    {
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}