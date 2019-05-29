class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        table[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!table.count(key)) {
            return "";
        }

        auto it = table[key].upper_bound(timestamp);
        if (it == table[key].begin()) {
            return "";
        }
        return (--it)->second;
    }

private:
    unordered_map<string, map<int, string>> table;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
