class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLen = 0;
        int n = s.size();
        vector<int> table(256);
        int count = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && count <= k) {
                ++table[s[j]];
                if (table[s[j]] == 1) {
                    ++count;
                }
                
                if (count <= k) {
                    maxLen = max(maxLen, j - i + 1);
                }
                ++j;
            }
            
            if (table[s[i]] == 1) {
                --count;
            }
            --table[s[i]];
        }
        
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLen = 0;
        vector<int> table(256);
        int count = 0;
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (table[s[j]]++ == 0) ++count;
            while (count > k) {
                if (--table[s[i]] == 0) {
                    --count;
                }
                ++i;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        int maxLen = 0;
        unordered_map<char, int> window;
        map<int, char> last;
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            char c = s[j];
            if (window.size() == k && !window.count(c)) {
                auto it = last.begin();
                last.erase(it);
                window.erase(it->second);
                i = it->first + 1;
            }

            if (window.count(c)) {
                last.erase(window[c]);
            }
            window[c] = j;
            last[j] = c;

            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
