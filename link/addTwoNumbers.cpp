
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(0, nullptr);
        ListNode *last = new ListNode(0, ans);
        int sum = l1->val + l2->val;
        int cnt = sum % 10; // 得到个位
        int cout = sum / 10;
        ans->val = cnt;
        last->val = last->val + cout;
        ListNode *next = new ListNode(0, nullptr);
        if (cout == 0)
            ans->next = nullptr;
        else{
            ans->next = last;
        }
        last = ans;
        ans = next;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 && l2)
        {
            int sum = l1->val + l2->val;
            int cnt = sum % 10; // 得到个位
            int cout = sum / 10;
            ans->val = cnt;
            last->val = last->val + cout;
            ListNode *next = new ListNode(0, nullptr);
            ans->next = last;
            last = ans;
            ans = next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int sum = l1->val;
            int cnt = sum % 10; // 得到个位
            int cout = sum / 10;
            ans->val = cnt;
            last->val = last->val + cout;
            ListNode *next = new ListNode(0, nullptr);
            ans->next = last;
            last = ans;
            ans = next;
            l1 = l1->next;
        }
        while (l2)
        {
            int sum = l2->val;
            int cnt = sum % 10; // 得到个位
            int cout = sum / 10;
            ans->val = cnt;
            last->val = last->val + cout;
            ListNode *next = new ListNode(0, nullptr);
            ans->next = last;
            last = ans;
            ans = next;
            l2 = l2->next;
        }
        ans->next = last;
        return ans;
    }
};
