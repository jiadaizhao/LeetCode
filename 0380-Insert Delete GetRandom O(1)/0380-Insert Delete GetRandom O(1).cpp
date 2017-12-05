class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (indexTable.find(val) != indexTable.end()) {
            return false;
        }
        
        indexTable[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (indexTable.find(val) == indexTable.end()) {
            return false;
        }
        
        int index = indexTable[val];
        int last = nums.back();
        indexTable[last] = index;
        nums[index] = last;
        nums.pop_back();
        indexTable.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
private:
    vector<int> nums;
    unordered_map<int, int> indexTable;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
 