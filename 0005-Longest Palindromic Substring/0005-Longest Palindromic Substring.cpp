// Expand from the middle
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }
        
        int maxStart = 0;
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int start = i, end = i;
            int len = 1;
            --start;
            ++end;
            while (start >= 0 && end < n && s[start] == s[end]) {
                --start;
                ++end;
                len += 2;
            }
            
            if (len > maxLen) {
                maxStart = i - len / 2;
                maxLen = len;
            }
            
            start = i;
            end = i + 1;
            len = 0;
            while (start >= 0 && end < n && s[start] == s[end]) {
                --start;
                ++end;
                len += 2;
            }
            
            if (len > maxLen) {
                maxStart = i - len / 2 + 1;
                maxLen = len;
            }
        }
        
        return s.substr(maxStart, maxLen);
    }
};

// Using DP

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }

        vector<vector<bool>> isPalindrome(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
        }
        int maxLen = 1;
        int start = 0;
        for (int j = 1; j < n; ++j) {
            for (int i = j - 1; i >= 0; --i) {
                if (s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
