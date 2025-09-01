struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head,*slow = head;
        while (fast!=nullptr)
        {
            slow = slow->next;
            if(fast->next == nullptr){
                return nullptr;
            }
            fast = fast->next->next;
            if(fast==slow){
                ListNode *ptr = head;
                while(ptr!=slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};