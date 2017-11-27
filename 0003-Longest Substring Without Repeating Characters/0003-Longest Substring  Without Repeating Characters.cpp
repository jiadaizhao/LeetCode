// Using template: i means sliding window start, j means sliding
// window end.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        vector<int> table(256);
        
        int j = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (j < s.size() && table[s[j]] == 0) {
                ++table[s[j]];
                ++j;
            }
            maxLen = max(maxLen, j - i);
            --table[s[i]];
        }
        
        return maxLen;
    }
};

// Another solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        vector<int> table(256);
        
        int start = 0;
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++table[s[i]];
            ++count;

            while (table[s[i]] > 1) {
                --table[s[start]];
                --count;
                ++start;
            }

            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};
