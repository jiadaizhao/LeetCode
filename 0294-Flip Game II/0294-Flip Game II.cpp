class Solution {
public:
    bool canWin(string s) {        
        return helper(s);
    }
    
    bool helper(string& s) {
        if (table.find(s) != table.end()) {
            return table[s];
        }
        
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                if (!helper(s)) {
                    s[i] = s[i + 1] = '+';
                    return table[s] = true;
                }
                s[i] = s[i + 1] = '+';
            }
        }
        
        return table[s] = false;
    }
private:
    unordered_map<string, bool> table;
};
