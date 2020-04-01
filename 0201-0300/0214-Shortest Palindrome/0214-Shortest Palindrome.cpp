class Solution {
public:
    string shortestPalindrome(string s) {
        string r(s);
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> lps(t.size());
        int len = 0, i = 1;
        while (i < t.size()) {
            if (t[i] == t[len]) {
                lps[i++] = ++len;
            }
            else if (len != 0) {
                len = lps[len - 1];
            }
            else {
                ++i;
            }
        }
        
        return r + s.substr(len);
    }
};
