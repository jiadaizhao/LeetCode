// KMP
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int m = str.size();
        if (m == 0) {
            return false;
        }
        vector<int> lps(m);
        // KMP
        // length of the previous longest prefix suffix
        int len = 0;
 
        int i = 1;
        while (i < m) {
            if (str[i] == str[len]) {
                lps[i++] = ++len;
            }
            else if (len != 0) {
                len = lps[len - 1];
            }
            else {
                ++i;
            }
        }
        
        return lps[m - 1] && (m % (m - lps[m - 1]) == 0);
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s.substr(1) + s.substr(0, s.size() - 1);
        return ss.find(s) != string::npos; 
    }
};
