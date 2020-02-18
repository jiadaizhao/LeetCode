class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> table(256);
        int count = 0, start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (table[s[i]]++ == 0) {
                ++count;
                while (count > 2) {
                    if (--table[s[start++]] == 0) {
                        --count;
                    }
                }
            }            
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;        
    }
};
