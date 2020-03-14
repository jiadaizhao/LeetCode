class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        table = {0 : -1}
        curr = maxLen = 0
        for i, c in enumerate(s):
            index = 'aeiou'.find(c)
            if index != -1:
                curr ^= 1 << index
            if curr not in table:
                table[curr] = i
            else:
                maxLen = max(maxLen, i - table[curr])
        return maxLen
