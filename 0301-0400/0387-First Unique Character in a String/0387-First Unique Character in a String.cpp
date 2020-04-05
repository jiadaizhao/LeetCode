class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> table(26);
        for (char c : s) {
            ++table[c - 'a'];
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (table[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};
