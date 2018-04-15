class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }
        
        int maxLen = 0, maxStart = 0;
        for (int i = 0; i < n; ++i) {
            int len = 1;
            int left = i - 1, right = i + 1;
            while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
                --left;
                ++right;
                len += 2;
            }
            if (len > maxLen) {
                maxLen = len;
                maxStart = left + 1;
            }
            
            len = 0;
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
                --left;
                ++right;
                len += 2;
            }
            if (len > maxLen) {
                maxLen = len;
                maxStart = left + 1;
            }
        }
        return s.substring(maxStart, maxStart + maxLen);
    }
}
