class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> table(256);
        int maxLen = 0;
        int count = 0;
        int n = s.size();
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            while (j < n && count <= 2)
            {
                if(++table[s[j]] == 1)
                {
                    ++count;
                }
                
                if (count <= 2)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                ++j;
            }
            
            if (--table[s[i]] == 0)
            {
                --count;
            }
        }
        
        return maxLen;        
    }
};
