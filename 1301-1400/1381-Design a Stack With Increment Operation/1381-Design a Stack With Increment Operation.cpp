class CustomStack {
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (St.size() < maxSize) {
            St.push_back({x, 0});
        }
    }
    
    int pop() {
        if (St.empty()) {
            return -1;
        }
        int num = St.back().first;
        int inc = St.back().second;
        St.pop_back();
        if (!St.empty()) {
            St.back().second += inc;
        }
        return num + inc;
    }
    
    void increment(int k, int val) {
        if (!St.empty()) {
            St[min(int(St.size()), k) - 1].second += val;
        }
    }
    
private:
    vector<pair<int, int>> St;
    int maxSize;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
