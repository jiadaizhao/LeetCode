class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        table = [0] * 256
        start = maxLen = 0
        for i in range(len(s)):
            table[ord(s[i])] = table[ord(s[i])] + 1
            while table[ord(s[i])] > 1:
                index = ord(s[start])
                table[index] = table[index] - 1
                start = start + 1
            maxLen = max(maxLen, i - start + 1)

        return maxLen
