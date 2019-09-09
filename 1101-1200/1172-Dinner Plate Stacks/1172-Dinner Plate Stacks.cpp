class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    
    void push(int val) {
        if (stacks.empty()) {
            stacks.insert(table.size());
        }
        table[*stacks.begin()].push_back(val);
        if (table[*stacks.begin()].size() == capacity) {
            stacks.erase(stacks.begin());
        }
    }
    
    int pop() {
        if (table.empty()) {
            return -1;
        }
        else {
            return popAtStack(table.rbegin()->first);
        }
    }
    
    int popAtStack(int index) {
        if (!table.count(index) || table[index].empty()) {
            return -1;
        }
        
        int val = table[index].back();
        table[index].pop_back();
        stacks.insert(index);
        if (table[index].empty()) {
            table.erase(index);
        }
        return val;
    }
    
private:
    int capacity;
    map<int, vector<int>> table;
    set<int> stacks;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
