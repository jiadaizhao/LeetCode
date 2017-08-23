class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        S1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = peek();
        S2.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        if (S2.empty())
        {
            while (!S1.empty())
            {
                S2.push(S1.top());
                S1.pop();
            }
        }
        return S2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return S1.empty() && S2.empty();
    }

private:
    stack<int> S1, S2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
 