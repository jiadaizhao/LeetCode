class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        minFlip = count1 = 0
        for c in S:
            if c == '1':
                count1 += 1
            else:
                minFlip = min(minFlip + 1, count1)
        return minFlip
