class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        used.resize(maxNumbers);
        dict.resize(maxNumbers);
        index = 0;
        for (int i = 0; i < maxNumbers; ++i)
        {
            dict[i] = i;
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (index == used.size())
        {
            return -1;
        }
        
        int result = dict[index++];
        used[result] = true;
        return result;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {        
        return number >= 0 && number < used.size() && !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (check(number))
        {
            return;
        }
        
        used[number] = false;
        dict[--index] = number;
    }
    
private:
    vector<bool> used;
    vector<int> dict;
    int index;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
 