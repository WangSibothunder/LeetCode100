#include "ListNode.h"
#include <queue>
using namespace std;

class Solution {
public:
    struct Status
    {
        int val;
        ListNode* ptr;
        bool operator < (const Status &rhs) const{
            return val > rhs.val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <Status> q;
        //将所有链表的第一个节点加入优先队列
        for(auto node: lists){
            if(node) q.push({node->val,node});
        }
        ListNode *dummy = new ListNode(0,nullptr);
        ListNode *cur = dummy;
        while(!q.empty()){
            // 队列中有值就说明没有排序完成
            auto f = q.top();q.pop();
            cur->next = f.ptr;
            cur = cur->next;
            if(f.ptr->next) q.push({f.ptr->next->val,f.ptr->next});
        }
        return dummy->next;
    }
};