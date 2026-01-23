#include "link.h"
#include <cstdio>
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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int cnt = 0;
        if(left==right) return dummy->next;
        ListNode *reverseStart=new ListNode(0);//反转起点
        ListNode *reverseEnd=new ListNode(0);//反转终点
        ListNode *pre = dummy;
        ListNode *cur = head;
        while (cur!=nullptr&&cnt<=right)
        {
            ListNode* nxt = cur->next;
            if(cnt==left){
                pre->next = reverseEnd;//反转起点前一个指向反转终点
                reverseStart->val = cur->val;
                pre = reverseStart;
                cur = nxt;
                //reverseStart.next最后赋值
            } else if (cnt<=right&&cnt>left)
            {
                cur->next = pre;
                pre = cur;
                cur = nxt;
                if(cnt==right){
                    reverseEnd->val = pre->val;
                    reverseEnd->next = pre->next;
                    reverseStart->next = cur;
                }
            } else{
                pre = cur;
                cur = nxt;
            }
            cnt++;
        }
        return dummy->next;
        }
};
// int main()
// {
//     printf("hello world\n");
//     fflush(stdout);  // 立即刷新输出缓冲区
//     printf("before creatList\n");
//     fflush(stdout);
//     // Solution sol;
//     ListNode *head = new ListNode(0);
//     head = creatList({1, 2, 3, 4, 5});
//     printf("after creatList\n");
//     fflush(stdout);
//     // int left = 2, right = 4;
//     // ListNode *res = sol.reverseBetween(head, left, right);
//     // printList(head);
//     return 0;
// }