// KMP
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int m = str.size();
        if (m == 0)
        {
            return false;
        }
        vector<int> lps(m);
        // length of the previous longest prefix suffix
        int len = 0;
 
        int i = 1;
        while (i < m)
        {
            if (str[i] == str[len])
            {
                lps[i++] = ++len;
            }
            else // (pat[i] != pat[len])
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else // if (len == 0)
                {
                    lps[i++] = 0;
                }
            }
        }
        
        return lps[m - 1] && (m % (m - lps[m - 1]) == 0);
    }
};
