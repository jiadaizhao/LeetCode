class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++table[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto it = table.begin(); it != table.end(); ++it)
        {
            int val1 = it->first;
            int val2 = value - val1;
            if ((val1 == val2 && table[val1] > 1) || (val1 != val2 && table.find(val2) != table.end()))
            {
                return true;
            }
        }
        
        return false;
    }

private:
    unordered_map<int, int> table;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
 