class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> table(26);
        int count = p.size();
        for (char c : p) {
            ++table[c - 'a'];
        }
        
        vector<int> result;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (table[s[i] - 'a']-- > 0) {
                --count;
                if (count == 0) {
                    result.push_back(start);
                }
            }
            if (i - start + 1 == p.size()) {
                if (++table[s[start++] - 'a'] > 0) {
                    ++count;
                }
            }            
        }
        return result;
    }
};
