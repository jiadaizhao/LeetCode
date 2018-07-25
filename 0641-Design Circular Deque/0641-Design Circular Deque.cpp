class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        head = nullptr;
        tail = nullptr;
        sz = k;
        len = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        Node* node = new Node(value);
        node->next = head;
        if (head) {
            head->prev = node;
        }
        else {
            tail = node;
        }
        head = node;
        ++len;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        Node* node = new Node(value);
        if (isEmpty()) {
            head = node;
        }
        else {
            tail->next = node;
            node->prev = tail;            
        }
        tail = node;
        ++len;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        
        Node* node = head;
        head = node->next;
        if (len == 1) {
            tail = nullptr;
        }
        else {
            head->prev = nullptr;
        }        
        --len;
        delete node;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        
        Node* node = tail;
        tail = node->prev;
        if (len == 1) {
            head = nullptr;
        }
        else {
            tail->next = nullptr;
        }        
        --len;
        delete node;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return head->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return tail->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return len == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return len == sz;
    }
    
private:
    struct Node {
        int val;
        Node *prev, *next;
        Node(int v): val(v), prev(nullptr), next(nullptr) {}
    };
    Node *head, *tail;
    int sz, len;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
