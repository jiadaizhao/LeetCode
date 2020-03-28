class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
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
        int i = 1, l = 0;
        while (i < m) {
            if (target[i] == target[l]) {
                lps[i++] = ++l;
            }
            else if (l != 0) {
                l = lps[l - 1]; 
            }
            else {
                ++i;
            }
        }
        
        return lps;
    }
};
