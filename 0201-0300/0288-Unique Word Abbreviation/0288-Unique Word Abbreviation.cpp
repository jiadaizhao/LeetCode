class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (string s : dictionary) {
            string key = getKey(s);
            if (table.find(key) != table.end()) {
                if (table[key] != s) {
                    table[key] = "";
                }                
            }
            else {
                table[key] = s;
            }
        }
    }
    
    bool isUnique(string word) {
        string key = getKey(word);
        return table.find(key) == table.end() || table[key] == word;
    }
    
private:
    unordered_map<string, string> table;
    string getKey(string s) {
        if (s.size() <= 2) {
            return s;
        }
        
        return s[0] + to_string(s.size() - 2) + s[s.size() - 1];
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
 