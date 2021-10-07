class Solution:
    def longestAwesome(self, s: str) -> int:
        table = {0 : -1}
        mask = maxLen = 0
        for i, c in enumerate(s):
            mask ^= (1 << int(c))
            for j in range(10):
                mask2 = mask ^ (1 << j)
                if mask2 in table:
                    maxLen = max(maxLen, i - table[mask2])
            if mask in table:
                maxLen = max(maxLen, i - table[mask])
            else:
                table[mask] = i
        return maxLen
