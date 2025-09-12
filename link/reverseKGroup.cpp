#include "ListNode.h"
#include <vector>

using namespace std;

class Solution
{
public:
    pair<ListNode*, ListNode*> Reverse(ListNode *head, ListNode *tail)
    { //链表内部反转，因此tail后面不一定是nullptr
        return {tail,head};
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        //注意中间反转的时候，两边都要链接
        ListNode *slow = head;
        ListNode *fast = slow;
        for (int i = 0; i < k; i++)
        {
            fast = fast->next;//需要判断fast在移动的时候是否到了尾巴
        } 

        pair<ListNode*, ListNode*> res = Reverse(slow, fast);
        ListNode* temphead = res.first;
        ListNode* temptail = res.second;

    }
};