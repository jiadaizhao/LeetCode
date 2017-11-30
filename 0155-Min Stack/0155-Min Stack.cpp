class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (S.empty()) {
            minVal = x;
            S.push(0);
        }
        else {
            S.push(x - minVal);
            if (x < minVal) {
                minVal = x;
            }
        }
    }
    
    void pop() {
        long top = S.top();
        S.pop();
        if (top < 0) {
            minVal -= top;
        }
    }
    
    int top() {
        return S.top() < 0 ? minVal : S.top() + minVal;
    }
    
    int getMin() {
        return minVal;
    }
    
private:
    stack<long> S;
    long minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 