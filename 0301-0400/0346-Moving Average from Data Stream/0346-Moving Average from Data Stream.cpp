class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum = 0;
        capacity = size;
    }
    
    double next(int val) {
        if (Q.size() == capacity) {
            sum -= Q.front();
            Q.pop();
        }
        
        Q.push(val);
        sum += val;
        return (double)sum / Q.size(); 
    }
    
private:
    queue<int> Q;
    int sum;
    int capacity;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
 