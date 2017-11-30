class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q.push(x);
        int qs = Q.size();
        while (qs > 1) {
            Q.push(Q.front());
            Q.pop();
            --qs;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = Q.front();
        Q.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }

private:
    queue<int> Q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
 