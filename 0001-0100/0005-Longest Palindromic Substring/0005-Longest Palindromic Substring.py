class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        
        maxLen, maxStart = 0, 0
        for i in range(n):
            l, left, right = 1, i - 1, i + 1
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
                l += 2

            if l > maxLen:
                maxLen = l
                maxStart = left + 1
                
            l, left, right = 0, i, i + 1
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
                l += 2

            if l > maxLen:
                maxLen = l
                maxStart = left + 1
        
        return s[maxStart:maxStart + maxLen]
