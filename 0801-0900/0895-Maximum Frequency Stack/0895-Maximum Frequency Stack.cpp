class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        ++freqs[x];
        int f = freqs[x];
        freqStacks[f].push(x);
        maxFreq = max(maxFreq, f); 
    }
    
    int pop() {
        int x = freqStacks[maxFreq].top();
        freqStacks[maxFreq].pop();
        --freqs[x];
        if (freqStacks[maxFreq].size() == 0) {
            --maxFreq;
        }
        return x;
    }

private:
    unordered_map<int, int> freqs;
    unordered_map<int, stack<int>> freqStacks;
    int maxFreq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
