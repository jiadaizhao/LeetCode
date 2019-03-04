class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node *p = head;
        for (int i = 0; i < index; ++i) {
            if (p == nullptr) {
                return -1;
            }
            p = p->next;
        }
        return p ? p->val : -1;        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        if (head == nullptr) {
            tail = node;
        }
        node->next = head;
        head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node * node = new Node(val);
        if (tail == nullptr) {
            head = node;
        }
        else {
            tail->next = node;
        }
        tail = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
        }
        else {
            Node *p = head;
            for (int i = 0; i < index - 1; ++i) {
                if (p == nullptr) {
                    return;
                }
                p = p->next;
            }
            if (p == nullptr) {
                return;
            }
            Node *node = new Node(val);
            Node *next = p->next;
            p->next = node;
            node->next = next;
            if (next == nullptr) {
                tail = node;
            }
        }        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0) {
            if (head == nullptr) {
                return;
            }
            Node *node = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete node;
        }
        else {
            Node *p = head;
            for (int i = 0; i < index - 1; ++i) {
                if (p == nullptr) {
                    return;
                }
                p = p->next;
            }
            if (p == nullptr || p->next == nullptr) {
                return;
            }
            Node *next = p->next;
            p->next = next->next;
            if (tail == next) {
                tail = p;
            }
            delete next;
        }
        
    }
    
private:
    struct Node {
        int val;
        Node *next;
        Node(int v): val(v), next(nullptr){}
    };
    Node *head, *tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
