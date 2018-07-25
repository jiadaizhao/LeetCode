class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        table.resize(1000001);
    }
    
    void add(int key) {
        table[key] = true;
    }
    
    void remove(int key) {
        table[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return table[key];
    }
    
private:
    vector<bool> table;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
