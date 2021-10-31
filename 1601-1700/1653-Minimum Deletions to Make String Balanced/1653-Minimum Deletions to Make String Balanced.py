class Solution:
    def minimumDeletions(self, s: str) -> int:
        minDel = countb = 0
        for c in s:
            if c == 'b':
                countb += 1
            else:
                minDel = min(minDel + 1, countb)
        return minDel
