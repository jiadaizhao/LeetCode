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
        
        int start = 0;
        for (int i = 0; i < s2.size(); ++i) {
            if (--table[s2[i] - 'a'] == 0) {
                --count;
                if (count == 0 && i - start + 1 == s1.size()) {
                    return true;
                }
                
                while (count == 0) {
                    if (++table[s2[start] - 'a'] == 1) {
                        count += 1;
                    }
                    else if (i - start == s1.size()) {
                        return true;
                    }
                    ++start;
                }
            }
        }   
        
        return false;
    }
};


class Solution2 {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        vector<int> table(26);
        int count = s1.size();
        for (char c : s1) {
            ++table[c - 'a'];
        }
        
        int start = 0;
        for (int i = 0; i < s2.size(); ++i) {
            if (--table[s2[i] - 'a'] >= 0) {
                --count;
                if (count == 0) {
                    return true;
                }
            }
            
            if (i - start + 1 == s1.size()) {
                if (++table[s2[start++] - 'a'] > 0) {
                    ++count;
                }
            }
        }   
        
        return false;
    }
};
