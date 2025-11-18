struct ListNode
{
    int val;
    ListNode* next;
    ListNode* random;
    ListNode() : val(0), next(nullptr), random(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next),random(nullptr) {}
};
