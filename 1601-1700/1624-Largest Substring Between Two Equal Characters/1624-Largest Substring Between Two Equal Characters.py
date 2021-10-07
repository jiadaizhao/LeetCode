class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        maxLen = -1
        table = {}
        for i, c in enumerate(s):
            maxLen = max(maxLen, i - table.setdefault(c, i) - 1)
        return maxLen
