class Solution {
public:
    bool wordPattern(string pattern, string str) {
        stringstream ss(str);
        string s;
        int i = 0, n = pattern.size();
        unordered_map<string, char> table;
        unordered_set<char> chars;
        while (getline(ss, s, ' ')) {
            if (i >= n) {
                return false;
            }
            
            if (table.count(s)) {
                if (table[s] != pattern[i]) {
                    return false;
                }
            }
            else {
                if (chars.count(pattern[i])) {
                    return false;
                }
                table[s] = pattern[i];
                chars.insert(pattern[i]);
            }            
            ++i;
        }
        
        return i == n;
    }
};
