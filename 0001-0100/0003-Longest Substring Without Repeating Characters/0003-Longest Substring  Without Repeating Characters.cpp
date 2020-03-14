class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> table;
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (table.count(s[i]) && table[s[i]] >= start) {
                start = table[s[i]] + 1;
            }
            else {
                maxLen = max(maxLen, i - start + 1);
            }
            table[s[i]] = i;
        }

        return maxLen;
    }
};
