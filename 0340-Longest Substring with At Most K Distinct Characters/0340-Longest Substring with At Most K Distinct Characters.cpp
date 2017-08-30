class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLen = 0;
        int n = s.size();
        vector<int> table(256);
        int count = 0;
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            while (j < n && count <= k)
            {
                ++table[s[j]];
                if (table[s[j]] == 1)
                {
                    ++count;
                }
                
                if (count <= k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                ++j;
            }
            
            if (table[s[i]] == 1)
            {
                --count;
            }
            --table[s[i]];
        }
        
        return maxLen;
    }
};
