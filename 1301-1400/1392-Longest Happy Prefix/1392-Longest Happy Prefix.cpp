class Solution {
public:
    string longestPrefix(string s) {
        vector<int> lps(s.size());
        int l = 0, i = 1;
        while (i < s.size()) {
            if (s[i] == s[l]) {
                lps[i++] = ++l;
            }
            else if (l != 0) {
                l = lps[l - 1];
            }
            else {
                ++i;
            }
        }
        return s.substr(0, lps.back());
    }
};
