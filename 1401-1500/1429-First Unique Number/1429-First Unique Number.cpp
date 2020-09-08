class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            Q.push(num);
            ++table[num];
        }
    }
    
    int showFirstUnique() {
        while (!Q.empty() && table[Q.front()] > 1) {
            Q.pop();
        }
        return Q.size() ? Q.front() : -1;
    }
    
    void add(int value) {
        Q.push(value);
        ++table[value];
    }
    
private:
    unordered_map<int, int> table;
    queue<int> Q;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
