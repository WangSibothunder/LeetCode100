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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        // 思路：快指针两倍速，慢指针一倍速，这样可以找到中点
        ListNode* before_start = middle_list(head);
        // 找到中点之后，把后面的链表倒叙过来
        // 遍历一遍列表，每个元素判断是否相同
        ListNode* p1 = head;
        ListNode* p2 = reverse_list(before_start->next);
        bool flag = true;
        while (p1!= nullptr && p2 != nullptr) {
            if (p1->val != p2->val) {
                flag = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return flag;
    }
    ListNode* middle_list(ListNode* head) {
        // 快慢指针，慢指针寻找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse_list(ListNode* head) {
        ListNode* curr = head;
        ListNode* last = nullptr;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = last;
            last = curr;
            curr = temp;
        }
        return last;
    }
};