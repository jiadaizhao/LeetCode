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

# O(n)
class Solution2:
    def longestPalindrome(self, s: str) -> str:
        T = '#'.join('^{}$'.format(s))
        n = len(T)
        P = [0] * n
        C = R = 0
        for i in range(1, n - 1):
            if R > i:
                P[i] = min(R - i, P[2*C - i])
                
            while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
                P[i] += 1
                
            if i + P[i] > R:
                C, R = i, i + P[i]
                
        maxLen, ci = max((l, i) for i, l in enumerate(P))
        return s[(ci - maxLen)//2 : (ci + maxLen)//2]
