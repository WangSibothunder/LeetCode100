#include"link.h"
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        if(left==right) return head;
        ListNode* reverseStart,reverseEnd;
        while (head!=nullptr&&cnt!=right+1)
        {
            ListNode* temp = cur;
            ListNode* nxt = cur->next;
            if(cnt==left-1){
                //这个时候是要反转节点前一个节点
                reverseStart = temp;
            }
            else if(cnt>=left&&cnt<=right){
                //这个时候执行反转逻辑
                if(cnt==left) {
                    
                }
            }
        }
        
    }
};