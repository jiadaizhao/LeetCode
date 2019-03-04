class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        vector<int> table(26);
        int count = 0;
        for (char c : s1) {
            if (++table[c - 'a'] == 1) {
                ++count;
            }
        }
        
        int j = 0;
        for (int i = 0; i < s2.size() - s1.size() + 1; ++i) {
            while (j < s2.size() && count) {
                if (--table[s2[j] - 'a'] == 0) {
                    --count;
                }
                ++j;
            }
            
            if (count == 0 && j - i == s1.size()) {
                return true;
            }
            
            if (table[s2[i] - 'a']++ == 0) {
                ++count;
            }
        }        
        
        return false;
    }
};
