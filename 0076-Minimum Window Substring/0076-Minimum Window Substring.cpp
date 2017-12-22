class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m < n) {
            return "";
        }
        
        vector<int> table(256);
        int count = 0;
        for (char c : t) {
            ++table[c];
            ++count;
        }
        
        int j = 0;
        int minSize = m + 1;
        string result;
        for (int i = 0; i < m - n + 1; ++i) {
            while (j < m && count) {
                --table[s[j]];
                if (table[s[j]] >= 0) {
                    --count;
                }
                ++j;
            }
            
            if (count == 0 && j - i < minSize) {
                minSize = j - i;
                result = s.substr(i, minSize);
            }
            
            if (table[s[i]] >= 0) {
                ++count;
            }
            ++table[s[i]];
        }
        
        return result;
    }
};
