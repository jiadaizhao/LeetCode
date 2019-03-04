class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        reverse(rev.begin(), rev.end());
        string str = s + "#" + rev;
        int n = str.size();
        int len = 0;
        int i = 1;
        vector<int> lps(n);
        while (i < n) {
            if (str[i] == str[len]) {
                lps[i++] = ++len;
            }
            else if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i++] = 0;
            }
        }
        
        return rev.substr(0, rev.size() - len) + s;
    }
};
