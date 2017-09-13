class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> count(26);
        int maxLen = 1;
        for (int i = 0; i < p.size(); ++i)
        {
            if (i > 0 && (p[i - 1] - 'a' == (p[i] - 'a' + 25) % 26))
            {
                ++maxLen;
            }
            else
            {
                maxLen = 1;
            }
            
            count[p[i] - 'a'] = max(count[p[i] - 'a'], maxLen);
        }
        
        return accumulate(count.begin(), count.end(), 0);
    }
};
