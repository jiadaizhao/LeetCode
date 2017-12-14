class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        table[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int len = 0;
        if (gra == "Year") {
            len = 4;
        }
        else if (gra == "Month") {
            len = 7;
        }
        else if (gra == "Day") {
            len = 10;
        }
        else if (gra == "Hour") {
            len = 13;
        }
        else if (gra == "Minute") {
            len = 16;
        }
        else {
            len = 19;
        }
        
        string low = s.substr(0, len);
        string high = e.substr(0, len);
        vector<int> result;
        for (auto it = table.lower_bound(low); it != table.end(); ++it) {
            if (it->first.substr(0, len) > high) {
                break;
            }
            
            result.push_back(it->second);
        }
        
        return result;
    }
    
private:
    map<string, int> table;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
 