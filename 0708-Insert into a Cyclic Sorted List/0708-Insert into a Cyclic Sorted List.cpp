/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            Node *node = new Node(insertVal, nullptr);
            node->next = node;
            return node;
        }
        
        Node *prev = head, *curr = head->next;
        bool insert = false;
        while (curr != head) {
            if ((prev->val <= insertVal && insertVal <= curr->val) ||
                (prev->val > curr->val && (insertVal <= curr->val || insertVal >= prev->val))) {
                prev->next = new Node(insertVal, curr);
                insert = true;
                break;
            }
                
            prev = curr;
            curr = curr->next;
        }
        
        if (!insert) {
            prev->next = new Node(insertVal, curr);
        }
        
        return head;
    }
};
