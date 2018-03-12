class Solution {
public:
    string customSortString(string S, string T) {
        string result;
        vector<int> table(26);
        for (char c : T) {
            ++table[c - 'a'];
        }
        
        for (char c : S) {
            if (table[c - 'a'] > 0) {
                result += string(table[c - 'a'], c);
                table[c - 'a'] = 0;
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            if (table[i] > 0) {
                result += string(table[i], 'a' + i);
            }
        }
        return result;
    }
};
