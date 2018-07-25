class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        len = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (head == -1) {
            head = 0;
        }
        tail = (tail + 1) % data.size();
        data[tail] = value;
        ++len;
        return true;        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        if (head == tail) {
            head = -1;
            tail = -1;
        }
        else {
            head = (head + 1) % data.size();
        }
        --len;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return len == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return len == data.size();
    }
    
private:
    int head, tail, len;
    vector<int> data;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
