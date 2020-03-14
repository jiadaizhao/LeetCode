// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* p = head;
        while (p) {
            Node* np = new Node(p->val);
            np->next = p->next;
            np->random = p->random;
            p->next = np;
            p = np->next;
        }
        
        p = head;
        while (p) {
            if (p->next->random) {
                p->next->random = p->random->next;
            }
            
            p = p->next->next;
        }
        
        p = head;
        Node* nh = p->next;
        while (p) {
            Node* np = p->next;
            p->next = np->next;
            p = p->next;
            if (p) {
                np->next = p->next;
            }
        }
        
        return nh;
    }
};
