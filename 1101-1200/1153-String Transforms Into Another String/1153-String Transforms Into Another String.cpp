class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        unordered_map<char, char> table;
        for (int i = 0; i < str1.size(); ++i) {
            if (table.count(str1[i]) && table[str1[i]] != str2[i]) {
                return false;
            }
            table[str1[i]] = str2[i];
        }
        
        return unordered_set<char>(str2.begin(), str2.end()).size() < 26;
    }
};
