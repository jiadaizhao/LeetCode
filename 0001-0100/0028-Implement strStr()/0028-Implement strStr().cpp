class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) {
            return 0;
        }
        if (n < m) {
            return -1;
        }
        
        vector<int> lps = preprocess(needle);
        int i = 0, j = 0;
        while (i < n) {
            if (needle[j] == haystack[i]){
                ++i;
                ++j;
                if (j == m) {
                    return i - m;
                }
            }
            else if (j != 0) {
                j = lps[j - 1];
            }
            else {
                ++i;
            }
        }
        
        return -1;
    }
private:
    vector<int> preprocess(string target) {
        int m = target.size();
        vector<int> lps(m);
        int i = 1, len = 0;
        while (i < m) {
            if (target[i] == target[len]) {
                lps[i++] = ++len;
            }
            else if (len != 0) {
                len = lps[len - 1]; 
            }
            else {
                lps[i++] = 0;
            }
        }
        
        return lps;
    }
};
