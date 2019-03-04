class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m > n) {
            return isOneEditDistance(t, s);
        }
        
        if (n - m > 1) {
            return false;
        }
        
        int diff = 0;
        if (m == n) {
            for (int i = 0; i < m; ++i) {
                if (s[i] != t[i]) {
                    ++diff;
                    if (diff > 1) {
                        return false;
                    }
                }
            }
            
            return diff == 1;
        }
        else {
            for (int i = 0, j = 0; i < m; ++i, ++j) {
                if (s[i] != t[j]) {
                    ++diff;
                    --i;
                    if (diff > 1) {
                        return false;
                    }
                }
            }
            
            return true;
        }
    }
};
