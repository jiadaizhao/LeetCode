class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        table = {}
        start = maxLen = 0
        for i, c in enumerate(s):
            if c in table and start <= table[c]:
                start = table[c] + 1
            else:
                maxLen = max(maxLen, i - start + 1)
            table[c] = i
        return maxLen
