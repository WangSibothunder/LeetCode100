class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        for(Node *node = head;node!=nullptr;node = node->next->next){
            Node *NodeNew = new Node(node->val);
            NodeNew->next = node->next;
            node->next = NodeNew;
        }
        for(Node *node = head; node!=nullptr; node = node->next->next){
            node->next->random = (node->random != nullptr) ? node->random->next : nullptr;//我这里题目没太看懂，为什么.random.next

        }
        Node *NewHead = head->next;
        for(Node *node = head; node!=nullptr;node = node->next->next){
            Node *nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next!=nullptr)? nodeNew->next->next:nullptr;
        } return NewHead;
    }
};